#pragma once

#include "RE/Bethesda/MemoryManager.h"
#include "RE/Bethesda/bhkCharacterController.h"
#include "RE/Havok/hkVector4.h"
#include "RE/Havok/hknpCollisionQuery.h"
#include "RE/Havok/hknpCollisionQueryCollector.h"
#include "RE/Havok/hknpCollisionResult.h"
#include "RE/NetImmerse/NiPoint.h"

namespace RE
{
	class hknpBSWorld;
	class NiAVObject;

	struct bhkPickData
	{
	public:
		enum class COLLECTOR_TYPE;

		bhkPickData()
		{
			typedef bhkPickData*           func_t(bhkPickData*);
			static REL::Relocation<func_t> func{ REL::ID(526783) };
			func(this);
		}

		void SetStartEnd(const NiPoint3& start, const NiPoint3& end)
		{
			using func_t = decltype(&bhkPickData::SetStartEnd);
			static REL::Relocation<func_t> func{ REL::ID(747470) };
			return func(this, start, end);
		}

		void Reset()
		{
			using func_t = decltype(&bhkPickData::Reset);
			static REL::Relocation<func_t> func{ REL::ID(438299) };
			return func(this);
		}

		bool HasHit()
		{
			using func_t = decltype(&bhkPickData::HasHit);
			static REL::Relocation<func_t> func{ REL::ID(1181584) };
			return func(this);
		}

		float GetHitFraction()
		{
			using func_t = decltype(&bhkPickData::GetHitFraction);
			static REL::Relocation<func_t> func{ REL::ID(476687) };
			return func(this);
		}

		int32_t GetAllCollectorRayHitSize()
		{
			using func_t = decltype(&bhkPickData::GetAllCollectorRayHitSize);
			static REL::Relocation<func_t> func{ REL::ID(1288513) };
			return func(this);
		}

		bool GetAllCollectorRayHitAt(uint32_t i, hknpCollisionResult& res)
		{
			using func_t = decltype(&bhkPickData::GetAllCollectorRayHitAt);
			static REL::Relocation<func_t> func{ REL::ID(583997) };
			return func(this, i, res);
		}

		void SortAllCollectorHits()
		{
			using func_t = decltype(&bhkPickData::SortAllCollectorHits);
			static REL::Relocation<func_t> func{ REL::ID(1274842) };
			return func(this);
		}

		NiAVObject* GetNiAVObject() const
		{
			using func_t = decltype(&bhkPickData::GetNiAVObject);
			static REL::Relocation<func_t> func{ REL::ID(2277763) };
			return func(this);
		}

		hknpBody* GetBody()
		{
			using func_t = decltype(&bhkPickData::GetBody);
			static REL::Relocation<func_t> func{ REL::ID(1223055) };
			return func(this);
		}

		F4_HEAP_REDEFINE_NEW(bhkPickData);

		// members
		hknpRayCastQuery             castQuery;            // 00
		hknpRayCastQueryResult       result;               // 60
		hkRefPtr<hknpBSWorld>        castWorld;            // C0
		std::uint64_t                customCollideLayers;  // C8
		hknpCollisionQueryCollector* collector;            // D0
		COLLECTOR_TYPE               collectorType;        // D8
		bool                         incrementPickTime;    // DC
		bool                         allowFailedPicks;     // DD
		bool                         pickFailed;           // DE
	};
	static_assert(sizeof(bhkPickData) == 0xE0);
};
