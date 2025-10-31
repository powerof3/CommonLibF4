#pragma once

#include "RE/NetImmerse/NiNode.h"

namespace RE
{
	class BSCullingProcess;
	class NiCamera;
	class NiVisibleArray;

	class __declspec(novtable) BSSceneGraph :
		public NiNode  // 000
	{
	public:
		static constexpr auto RTTI{ RTTI::BSSceneGraph };
		static constexpr auto VTABLE{ VTABLE::BSSceneGraph };
		static constexpr auto Ni_RTTI{ Ni_RTTI::BSSceneGraph };

		// add
		virtual float GetFarDistance();                               // 43
		virtual float GetNearDistance();                              // 44
		virtual void  SetViewDistanceBasedOnFrameRate(float a_time);  // 44

		// members
		NiPointer<NiCamera> camera;          // 140
		NiVisibleArray*     visArray;        // 148
		BSCullingProcess*   culler;          // 150
		bool                menuSceneGraph;  // 158
		float               currentFOV;      // 15C
	};
	static_assert(sizeof(BSSceneGraph) == 0x160);

	class __declspec(novtable) SceneGraph :
		public BSSceneGraph  // 000
	{
		static constexpr auto RTTI{ RTTI::SceneGraph };
		static constexpr auto VTABLE{ VTABLE::SceneGraph };
		static constexpr auto Ni_RTTI{ Ni_RTTI::SceneGraph };

		// members
		float customNearDistance;        // 160
		float customFarDistance;         // 164
		bool  customNearDistanceActive;  // 168
		bool  customFarDistanceActive;   // 169
	};
	static_assert(sizeof(SceneGraph) == 0x170);
}
