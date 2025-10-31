#pragma once

#include "RE/NetImmerse/NiAVObject.h"
#include "RE/NetImmerse/NiBound.h"
#include "RE/NetImmerse/NiFrustum.h"
#include "RE/NetImmerse/NiRect.h"

namespace RE
{
	class __declspec(novtable) NiCamera :
		public NiAVObject  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::NiCamera };
		static constexpr auto VTABLE{ VTABLE::NiCamera };
		static constexpr auto Ni_RTTI{ Ni_RTTI::NiCamera };

		virtual ~NiCamera();  // 00

		// override
		virtual const NiRTTI* GetRTTI() const override;                             // 02
		virtual NiObject*     CreateClone(NiCloningProcess& a_cloneData) override;  // 1A
		virtual void          LoadBinary(NiStream& a_stream) override;              // 1B
		virtual void          LinkObject(NiStream& a_stream) override;              // 1C
		virtual bool          RegisterStreamables(NiStream& a_stream) override;     // 1D
		virtual void          SaveBinary(NiStream& a_stream) override;              // 1E
		virtual bool          IsEqual(NiObject* a_object) override;                 // 1F
		virtual void          UpdateWorldBound() override;                          // 33
		virtual void          UpdateWorldData(NiUpdateData* a_data) override;       // 34

		static bool BoundInFrustum(const NiBound& a_bound, RE::NiCamera* a_camera)
		{
			using func_t = decltype(&NiCamera::BoundInFrustum);
			static REL::Relocation<func_t> func{ REL::ID(2194525) };
			return func(a_bound, a_camera);
		}

		bool NodeInFrustum(NiAVObject* a_node)
		{
			if (!a_node) {
				return false;
			}

			return BoundInFrustum(a_node->worldBound, this);
		}

		bool PointInFrustum(const NiPoint3& a_point, float a_radius)
		{
			const NiBound bound{ a_point, a_radius };
			return BoundInFrustum(bound, this);
		}

		bool WorldPtToScreenPt3(const NiPoint3& a_point, float& a_x, float& a_y, float& a_z, float a_zeroTolerance) const
		{
			return WorldPtToScreenPt3(worldToCam, port, a_point, a_x, a_y, a_z, a_zeroTolerance);
		}

		static bool WorldPtToScreenPt3(const float a_matrix[4][4], const NiRect<float>& a_port, const NiPoint3& a_point, float& a_x, float& a_y, float& a_z, float a_zeroTolerance)
		{
			using func_t = bool (*)(const float[4][4], const NiRect<float>&, const NiPoint3&, float&, float&, float&, float);
			static REL::Relocation<func_t> func{ REL::ID(2270344) };
			return func(a_matrix, a_port, a_point, a_x, a_y, a_z, a_zeroTolerance);
		}

		// members
		float         worldToCam[4][4];  // 120
		NiFrustum     viewFrustum;       // 160
		float         minNearPlaneDist;  // 17C
		float         maxFarNearRatio;   // 180
		NiRect<float> port;              // 184
		float         lodAdjust;         // 194
	};
	static_assert(sizeof(NiCamera) == 0x1A0);
}
