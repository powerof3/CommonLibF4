#pragma once

#include "RE/Havok/hkVector4.h"

namespace RE
{
	class hkcdRay
	{
	public:
		// members
		hkVector4f origin;        // 00
		hkVector4f direction;     // 10
		hkVector4f invDirection;  // 20
	};
	static_assert(sizeof(hkcdRay) == 0x30);
}
