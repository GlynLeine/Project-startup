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
		std::pair<Collider*,Rigidbody*> colliders;
		std::set<uint32> entities;
		void ResolveCollisions();
	};
}
