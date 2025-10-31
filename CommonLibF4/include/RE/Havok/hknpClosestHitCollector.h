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
			typedef hknpClosestHitCollector* func_t(hknpClosestHitCollector*);
			static REL::Relocation<func_t>   func{ REL::ID(2188714) };
			func(this);
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
