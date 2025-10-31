#pragma once

#include "RE/Havok/hkVector4.h"

namespace RE
{
	class hkAabb
	{
	public:
		// members
		hkVector4f min;  // 00
		hkVector4f max;  // 10
	};
	static_assert(sizeof(hkAabb) == 0x20);
}
