#include "RE/NetImmerse/NiAVObject.h"

#include "RE/NetImmerse/NiCollisionObject.h"

namespace RE
{
	NiAVObject::NiAVObject()
	{
		emplace_vtable(this);
		local.MakeIdentity();
		world.MakeIdentity();
		previousWorld.MakeIdentity();
		flags.flags = 0xE;
	}

	NiAVObject::~NiAVObject() {}
}
