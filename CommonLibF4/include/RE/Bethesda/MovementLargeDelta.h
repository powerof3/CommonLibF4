#pragma once

#include "RE/Bethesda/BSFixedString.h"

namespace RE
{
	namespace MovementLargeDelta
	{
		enum class SPEED;

		enum class FROM_DIRECTION
		{
			kFacingForward = 0,
			kStrafingRight = 1,
			kStrafingBackward = 2,
			kStrafingLeft = 3,

			kTotal = 4,
		};

		enum class TO_DIRECTION
		{
			kFacingForward = 0,
			kStrafingRight = 1,
			kStrafingBackward = 2,
			kStrafingLeft = 3,
			kFacingRight = 4,
			kFacingBackward = 5,
			kFacingLeft = 6,

			kTotal = 0x7,
		};

		struct CurrentState
		{
		public:
			// members
			REX::Enum<SPEED, std::uint32_t>          fromSpeed;      // 00
			REX::Enum<FROM_DIRECTION, std::uint32_t> fromDirection;  // 04
		};
		static_assert(sizeof(CurrentState) == 0x8);

		struct DesiredState
		{
		public:
			// members
			REX::Enum<SPEED, std::uint32_t>        toSpeed;
			REX::Enum<TO_DIRECTION, std::uint32_t> toDirection;
		};
		static_assert(sizeof(DesiredState) == 0x8);

		struct IdleSelectionData
		{
		public:
			// members
			CurrentState fromState;  // 00
			DesiredState toState;    // 08
		};
		static_assert(sizeof(IdleSelectionData) == 0x10);
	}
}
