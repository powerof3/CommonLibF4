#pragma once

#include "RE/Bethesda/BSFixedString.h"
#include "RE/Bethesda/BSTHashMap.h"

namespace RE
{
	class BGSActionData;

	class BGSAnimationSequencer
	{
	public:
		// members
		std::uint32_t                             numSequences;  // 00
		BSTHashMap<BSFixedString, BGSActionData*> actions;       // 08
	};
	static_assert(sizeof(BGSAnimationSequencer) == 0x38);
}
