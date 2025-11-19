#pragma once

#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSPointerHandle.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTOptional.h"
#include "RE/Havok/hkRefPtr.h"

namespace RE
{
	class hknpSphereShape;
	class NiAVObject;
	class NiPoint3;
	enum class ACTOR_LIFE_STATE;

	struct ViewCasterData
	{
		// members
		ObjectRefHandle activatePickRef;     // 00
		ObjectRefHandle magnetismRef;        // 04
		ObjectRefHandle telekinesisPickRef;  // 08
		ObjectRefHandle dialoguePickRef;     // 0C
		NiAVObject*     avObject;            // 10
		NiAVObject*     shapeCastAVObject;   // 18
		uint32_t        collisionGroup;      // 20
	};
	static_assert(sizeof(ViewCasterData) == 0x28);

	struct ViewCasterUpdateData
	{
		// members
		ViewCasterData                currentVCData;       // 00
		bool                          playerActivateable;  // 28
		BSTOptional<ACTOR_LIFE_STATE> actorLifeState;      // 2C
	};
	static_assert(sizeof(ViewCasterUpdateData) == 0x38);

	class ViewCasterUpdateEvent : public BSTValueEvent<ViewCasterUpdateData>
	{
	private:
		using EventSource_t = BSTGlobalEvent::EventSource<ViewCasterUpdateEvent>;

	public:
		[[nodiscard]] static EventSource_t* GetEventSource()
		{
			static REL::Relocation<EventSource_t**> singleton{ REL::ID(2694310) };
			if (!*singleton) {
				*singleton = new EventSource_t(&BSTGlobalEvent::GetSingleton()->eventSourceSDMKiller);
			}
			return *singleton;
		}
	};
	static_assert(sizeof(ViewCasterUpdateEvent) == 0x40);

	class ViewCasterBase
	{
	public:
		ObjectRefHandle QActivatePickRef()
		{
			BSAutoReadLock locker(viewCasterLock);
			return GetViewCasterDataRef().activatePickRef;
		}

		// members
		BSTValueEventSource<ViewCasterUpdateEvent> viewCasterEvent;   // 00
		BSTOptional<NiPoint3>                      pickContactPoint;  // 50
		BSReadWriteLock                            viewCasterLock;    // 60

	private:
		const ViewCasterData& GetViewCasterDataRef()
		{
			using func_t = decltype(&ViewCasterBase::GetViewCasterDataRef);
			static REL::Relocation<func_t> func{ REL::ID(2219551) };
			return func(this);
		}
	};
	static_assert(sizeof(ViewCasterBase) == 0x68);

	class ViewCaster :
		public ViewCasterBase,              // 00
		public BSTSingletonSDM<ViewCaster>  // 68
	{
	public:
		[[nodiscard]] static ViewCaster* GetSingleton()
		{
			static REL::Relocation<ViewCaster**> singleton{ REL::ID(4797738) };
			return *singleton;
		}

		// members
		hkRefPtr<hknpSphereShape> castShape;  // 70
	};
	static_assert(sizeof(ViewCaster) == 0x78);
}
