#pragma once

#include "RE/Scaleform/GFx/GFx_Player.h"

namespace RE
{
	class SWFToCodeFunctionHandler :
		public Scaleform::GFx::FunctionHandler  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::SWFToCodeFunctionHandler };
		static constexpr auto VTABLE{ VTABLE::SWFToCodeFunctionHandler };

		virtual ~SWFToCodeFunctionHandler() = default;

		// override (Scaleform::GFx::FunctionHandler)
		void Call(const Params&) override { return; }  // 01

		// add
		virtual void MapCodeObjectFunctions() { return; }  // 02

		void RegisterCodeObject(Scaleform::GFx::Movie& a_movie, Scaleform::GFx::Value& a_menuObj)
		{
			using func_t = decltype(&SWFToCodeFunctionHandler::RegisterCodeObject);
			REL::Relocation<func_t> func{ REL::ID(67637) };
			return func(this, a_movie, a_menuObj);
		}
	};
	static_assert(sizeof(SWFToCodeFunctionHandler) == 0x10);
}
