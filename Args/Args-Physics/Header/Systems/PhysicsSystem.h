#pragma once
#include <Args-Core.h>
#include "Components/Collider.h"
#include "Components/Rigidbody.h"

namespace Args
{
	class PhysicsSystem : public Args::MonoUpdateSystem<PhysicsSystem>
	{
	public:
		PhysicsSystem();
		~PhysicsSystem();
	private:
		void ResolveCollisions();
		Vector3 Reflect(Vector3 surfaceNormal, Vector3 incomingVec);
	};
}
