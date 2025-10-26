#pragma once

#include "RE/Bethesda/BSInputEventReceiver.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTSingleton.h"

namespace RE
{
	class MenuOpenCloseEvent;

	struct IdleInputEvent;

	class BSIdleInputWatcher :
		public BSInputEventReceiver,
		public BSTEventSink<MenuOpenCloseEvent>,
		public BSTSingletonSDM<BSIdleInputWatcher>,
		public BSTEventSource<IdleInputEvent>
	{
	public:
		[[nodiscard]] static BSIdleInputWatcher* GetSingleton()
		{
			static REL::Relocation<BSIdleInputWatcher**> singleton{ REL::ID(2693716) };
			return *singleton;
		}

		// members
		std::uint64_t lastInputTime;  // 78
		std::uint8_t  disableCount;   // 80
		bool          isInputIdle;    // 81
	};
	static_assert(sizeof(BSIdleInputWatcher) == 0x88);
}
