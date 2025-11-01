#pragma once

#include "RE/Bethesda/CFilter.h"
#include "RE/Havok/hkBaseTypes.h"
#include "RE/Havok/hkcdRay.h"
#include "RE/Havok/hknpMaterialId.h"

namespace RE
{
	class hknpCollisionFilter;

	struct hknpQueryFilterData
	{
		hknpMaterialId          materialId;           // 00
		hkPadSpu<CFilter>       collisionFilterInfo;  // 04
		hkPadSpu<std::uint64_t> userData;             // 08
	};
	static_assert(sizeof(hknpQueryFilterData) == 0x10);

	struct hknpCollisionQuery
	{
	public:
		// members
		hkPadSpu<hknpCollisionFilter*> filter;         // 00
		hknpQueryFilterData            filterData;     // 08
		std::int8_t                    levelOfDetail;  // 18
	};
	static_assert(sizeof(hknpCollisionQuery) == 0x20);

	class hkcdRayQueryFlags
	{
	public:
		enum class Enum
		{
			kNoFlags = 0x0,
			kDisableBackFacingTriangleHits = 0x1,
			kDisableFrontFacingTriangleHits = 0x2,
			kEnableInsideHits = 0x4,
			kEnableExtraTriangleBevelplanes = 0x8
		};
	};
	static_assert(std::is_empty_v<hkcdRayQueryFlags>);

	struct hknpRayCastQuery :
		public hknpCollisionQuery  // 00
	{
		// members
		hkcdRay                                        ray;    // 20
		hkFlags<hkcdRayQueryFlags::Enum, unsigned int> flags;  // 50
	};
	static_assert(sizeof(hknpRayCastQuery) == 0x60);
}
