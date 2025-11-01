#pragma once

#include "RE/Bethesda/BSPointerHandle.h"
#include "RE/Bethesda/BSTArray.h"
#include "RE/Bethesda/BSTEvent.h"
#include "RE/Bethesda/BSTSingleton.h"

namespace RE
{
	class HUDSubtitleDisplayEvent;

	enum class SUBTITLE_PRIORITY
	{
		kLow = 0,
		kNormal = 1,
		kHigh = 2,
		kForce = 3,

		kTotal
	};
	
	class SubtitleInfo
	{
	public:
		//members
		ObjectRefHandle              speaker;         // 00
		BSFixedStringCS              subtitleText;    // 08
		TESTopicInfo*                topicInfo;       // 10
		REX::Enum<SUBTITLE_PRIORITY> priority;        // 18
		float                        distFromPlayer;  // 1C
	};
	static_assert(sizeof(SubtitleInfo) == 0x20);

	class SubtitleManager :
		public BSTSingletonSDM<SubtitleManager>  // 00
	{
	public:
		[[nodiscard]] static SubtitleManager* GetSingleton()
		{
			static REL::Relocation<SubtitleManager**> singleton{ REL::ID(2689088) };
			return *singleton;
		}

		[[nodiscard]] static BSReadWriteLock& GetRWLock()
		{
			static REL::Relocation<BSReadWriteLock*> rwLock{ REL::ID(2701704) };
			return *rwLock;
		}

		// members
		BSTArray<SubtitleInfo, BSTArrayHeapAllocator> subtitlePriorityArray;
		ObjectRefHandle                               currentSpeaker;
		BSTValueEventSource<HUDSubtitleDisplayEvent>  subtitleDisplayData;
	};
	static_assert(sizeof(SubtitleManager) == 0x50);
}
