#pragma once

#include "RE/Bethesda/CFilter.h"
#include "RE/Havok/hkBaseTypes.h"
#include "RE/Havok/hkVector4.h"
#include "RE/Havok/hknpBodyId.h"
#include "RE/Havok/hknpMaterialId.h"

namespace RE
{
	struct hknpCollisionQueryType
	{
	public:
		enum class Enum
		{
			kAllHits = 0,
			kClosestHit = 1,
		};
	};

	struct hknpCollisionResult
	{
	public:
		struct BodyInfo
		{
		public:
			// members
			hknpBodyId              bodyId;                    // 00
			hknpMaterialId          shapeMaterialId;           // 04
			hkPadSpu<std::uint32_t> shapeKey;                  // 08
			hkPadSpu<CFilter>       shapeCollisionFilterInfo;  // 0C
			hkPadSpu<std::size_t>   shapeUserData;             // 10
		};
		static_assert(sizeof(BodyInfo) == 0x18);

		// members
		hkVector4f                                               position;       // 00
		hkVector4f                                               normal;         // 10
		hkPadSpu<float>                                          fraction;       // 20
		BodyInfo                                                 queryBodyInfo;  // 28
		BodyInfo                                                 hitBodyInfo;    // 40
		REX::EnumSet<hknpCollisionQueryType::Enum, std::int32_t> queryType;      // 58
		hkPadSpu<std::uint32_t>                                  hitResult;      // 5C
	};
	static_assert(sizeof(hknpCollisionResult) == 0x60);

	class hknpRayCastQueryResult :
		public hknpCollisionResult
	{
	public:
	};
	static_assert(sizeof(hknpRayCastQueryResult) == 0x60);
}
