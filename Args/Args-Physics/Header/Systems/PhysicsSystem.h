#pragma once
#include <Args-Core.h>
#include "Components/Collider.h"
#include "Components/Rigidbody.h"

namespace Args
{
	class PhysicsSystem : public Args::MonoUpdateSystem<PhysicsSystem, Rigidbody, Collider, Transform>
	{
	public:
		virtual void Init() override;
	private:
		void ResolveCollisions(float deltaTime);
		Vector3 Reflect(Vector3 surfaceNormal, Vector3 incomingVec, float bounciness);
	};
}
