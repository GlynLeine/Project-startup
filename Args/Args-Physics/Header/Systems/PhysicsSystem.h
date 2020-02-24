#pragma once
#include <Args-Core.h>

namespace Args
{
	class PhysicsSystem : public Args::GlobalSystem<PhysicsSystem>
	{
	public:
		PhysicsSystem();
		~PhysicsSystem();
	private:
		void ResolveCollisions();
	};
}
