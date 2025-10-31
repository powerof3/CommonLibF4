#pragma once

#include "RE/Havok/hkMemoryAllocator.h"

namespace RE
{
	struct hkContainerHeapAllocator
	{
	public:
		class Allocator :
			public hkMemoryAllocator
		{
		public:
		};
		static_assert(sizeof(Allocator) == 0x08);
	};
	static_assert(std::is_empty_v<hkContainerHeapAllocator>);
}
