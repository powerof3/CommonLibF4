#pragma once

#include "RE/Bethesda/COL_LAYERS.h"

namespace RE
{
	enum class BIPED_PART
	{
		kOther = 0,
		kHead = 1,
		kBody = 2,
		kSpine1 = 3,
		kSpine2 = 4,
		kLUpperArm = 5,
		kLForearm = 6,
		kLHand = 7,
		kLThigh = 8,
		kLCalf = 9,
		kLFoot = 10,
		kRUpperArm = 11,
		kRForearm = 12,
		kRHand = 13,
		kRThigh = 14,
		kRCalf = 15,
		kRFoot = 16,
		kTail = 17,
		kShield = 18,
		kQuiver = 19,
		kWeapon = 20,
		kPonytail = 21,
		kWing = 22,
		kPack = 23,
		kChain = 24,
		kAddonHead = 25,
		kAddonChest = 26,
		kAddonLeg = 27,
		kAddonArm = 28,

		kTotal = 32
	};

	class CFilter
	{
	public:
		struct Flags
		{
			enum Flag
			{
				kNone = 0,
				kNoCollision = 1 << 14,
				kLinkedGroup = 1 << 15,

				kPartMask = 0x1F,  // BIPED_PART
				kLayerMask = 0x7F  // COL_LAYER
			};
		};

		CFilter(std::uint32_t a_filter = 0) :
			filter(a_filter)
		{}

		COL_LAYER     GetCollisionLayer() const { return static_cast<COL_LAYER>(filter & Flags::kLayerMask); }
		BIPED_PART    GetBipedPart() const { return static_cast<BIPED_PART>((filter >> 8) & Flags::kPartMask); }
		bool          QNoCollision() const { return (filter >> 14) & 1; }
		bool          QLinkedGroup() const { return (filter >> 15) & 1; }
		std::uint32_t GetSystemGroup() const { return filter >> 16; }

		void SetCollisionLayer(COL_LAYER a_layer)
		{
			filter &= ~(Flags::kLayerMask);
			filter |= (std::to_underlying(a_layer) & Flags::kLayerMask);
		}

		void SetBipedPart(BIPED_PART a_part)
		{
			filter &= ~(Flags::kPartMask << 8);
			filter |= ((std::to_underlying(a_part) & Flags::kPartMask) << 8);
		}

		void SetNoCollision(bool a_set)
		{
			if (a_set) {
				filter |= Flags::kNoCollision;
			} else {
				filter &= ~Flags::kNoCollision;
			}
		}

		void SetLinkedGroup(bool a_set)
		{
			if (a_set) {
				filter |= Flags::kLinkedGroup;
			} else {
				filter &= ~Flags::kLinkedGroup;
			}
		}

		void SetSystemGroup(std::uint32_t a_group)
		{
			filter &= 0x0000FFFF;
			filter |= a_group << 16;
		}

		// members
		std::uint32_t filter;  // 0
	};
	static_assert(sizeof(CFilter) == 0x4);
}
