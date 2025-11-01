#pragma once

#include "RE/Bethesda/BSFixedString.h"

namespace RE
{
	namespace AnimationSpeedInformationTypes
	{
		struct AnimationStateAdjustment
		{
		public:
			union Variable
			{
				float variableFloatValue;
				int   variableIntValue;
			};

			// members
			BSFixedString adjustmentName;      // 00
			Variable      adjustmentVariable;  // 08
			bool          useFloat;            // 0C
			bool          isVariable;          // 0D
		};
		static_assert(sizeof(AnimationStateAdjustment) == 0x10);
	}
}
