#pragma once

#include "RE/Havok/hkArray.h"
#include "RE/Havok/hkBaseTypes.h"
#include "RE/Havok/hknpMotionId.h"

namespace RE
{
	class hknpBodyManager;
	class hknpMotion;

	class hknpMotionManager
	{
	public:
		class CellData
		{
		public:
			// members
			hkArray<hknpMotionId> solverIdToMotionId;  // 10
		};
		static_assert(sizeof(CellData) == 0x10);

		// members
		hknpBodyManager*    bodyManager;              // 00
		hkArray<hknpMotion> motions;                  // 08
		hkBool              motionBufferIsUserOwned;  // 18
		hknpMotionId        firstFreeMotionId;        // 1C
		hknpMotionId        firstMarkedMotionId;      // 20
		std::uint32_t       numAllocatedMotions;      // 24
		std::uint32_t       numMarkedMotions;         // 28
		std::uint32_t       peakMotionIndex;          // 2C
		hkArray<CellData>   activeMotionGrid;         // 30
		hkBool              isLocked;                 // 40
	};
	static_assert(sizeof(hknpMotionManager) == 0x48);
}
