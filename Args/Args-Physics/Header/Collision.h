#pragma once
#include <Args-Math.h>
#include "Components/Collider.h"

namespace Args
{
	struct Collision
	{
		Collider* other;
		Vector3 impulse;
		Vector3 normal;
		float penetration;

		Collision() : other(nullptr) {}

		operator bool()
		{
			return other != nullptr;
		}
	};
}

namespace std
{
	class HIV
	{

	};
}
