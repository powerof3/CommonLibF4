#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSLock.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTSingleton.h"
#include "RE/Bethesda/UIMessage.h"

namespace RE
{
	class UIMessageQueue :
		public BSTSingletonSDM<UIMessageQueue>  // 000
	{
	public:
		[[nodiscard]] static UIMessageQueue* GetSingleton()
		{
			static REL::Relocation<UIMessageQueue**> singleton{ REL::ID(2689091) };
			return *singleton;
		}

		void AddMessage(const BSFixedString& a_menu, UI_MESSAGE_TYPE a_type)
		{
			using func_t = decltype(&UIMessageQueue::AddMessage);
			static REL::Relocation<func_t> func{ REL::ID(2284929) };
			return func(this, a_menu, a_type);
		}

		// members
		BSTSmallArray<std::unique_ptr<UIMessage>, 64> messages;        // 008
		BSSpinLock                                    uiMessagesLock;  // 218
	};
	static_assert(sizeof(UIMessageQueue) == 0x220);
}
