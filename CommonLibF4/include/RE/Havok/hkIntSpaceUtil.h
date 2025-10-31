#pragma once

#include "RE/Havok/hkAabb.h"
#include "RE/Havok/hkVector4.h"

namespace RE
{
	class hkIntSpaceUtil
	{
	public:
		// members
		hkVector4f bitOffsetLow;   // 00
		hkVector4f bitOffsetHigh;  // 10
		hkVector4f bitScale;       // 20
		hkVector4f bitScaleInv;    // 30
		hkAabb     aabb;           // 40
	};
	static_assert(sizeof(hkIntSpaceUtil) == 0x60);
}
