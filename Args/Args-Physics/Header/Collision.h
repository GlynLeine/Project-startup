#pragma once
#include <Args-Math.h>
#include "Components/Collider.h"

namespace Args 
{
	struct Collision
	{
		Collider other;
		Vec3 impulse;
	};
}
