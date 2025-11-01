#pragma once

#include "RE/Havok/hkArray.h"
#include "RE/Havok/hknpCollisionQueryCollector.h"
#include "RE/Havok/hknpCollisionResult.h"

namespace RE
{
	class __declspec(novtable) hknpClosestHitCollector :
		public hknpCollisionQueryCollector  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::hknpClosestHitCollector };
		static constexpr auto VTABLE{ VTABLE::hknpClosestHitCollector };

		hknpClosestHitCollector()
		{
			this->hints = 0;
			this->earlyOutThreshold.real = __m128{};
			this->result.queryType.reset();
			this->result.fraction.storage = 3.40282e38f;
			this->result.position = NiPoint3();
			this->result.normal = NiPoint3();
			this->result.queryBodyInfo.bodyId.value = 0x7FFFFFFF;
			this->result.queryBodyInfo.shapeKey.storage = static_cast<std::uint32_t>(-1);
			this->result.queryBodyInfo.shapeMaterialId.value = static_cast<std::uint16_t>(-1);
			this->result.queryBodyInfo.shapeCollisionFilterInfo.storage = 0;
			this->result.queryBodyInfo.shapeUserData.storage = 0;
			this->result.hitBodyInfo.bodyId.value = 0x7FFFFFFF;
			this->result.hitBodyInfo.shapeKey.storage = static_cast<std::uint32_t>(-1);
			this->result.hitBodyInfo.shapeMaterialId.value = static_cast<std::uint16_t>(-1);
			this->result.hitBodyInfo.shapeCollisionFilterInfo.storage = 0;
			this->result.hitBodyInfo.shapeUserData.storage = 0;
			this->hasHit.b = 0;

			stl::emplace_vtable<hknpClosestHitCollector>(this);
		}

		// override (hknpCollisionQueryCollector)
		void Reset() override  // 01
		{
			using func_t = decltype(&hknpClosestHitCollector::Reset);
			static REL::Relocation<func_t> func{ REL::ID(2188722) };
			return func(this);
		}

		void AddHit(const hknpCollisionResult& a_hit) override  // 02
		{
			using func_t = decltype(&hknpClosestHitCollector::AddHit);
			static REL::Relocation<func_t> func{ REL::ID(2188722) };
			return func(this, a_hit);
		}

		bool                       HasHit() const override { return hasHit.b; }      // 03
		std::int32_t               GetNumHits() const override { return HasHit(); }  // 04
		const hknpCollisionResult* GetHits() const override { return &result; }      // 05

		// members
		hknpCollisionResult result;  // 20
		hkBool              hasHit;  // 80
	};
	static_assert(sizeof(hknpClosestHitCollector) == 0x90);
}
