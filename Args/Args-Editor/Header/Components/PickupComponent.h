#pragma once
#include <Args-Core.h>

namespace Args
{
	struct PickupComponent
	{
		bool PickingUp;
		float VertThrowPow;
		float HorThrowPow;
		uint32 PickedUpObject;
	};
}