#include <Systems/PhysicsSystem.h>


Args::PhysicsSystem::PhysicsSystem()
{
	
}

Args::PhysicsSystem::~PhysicsSystem()
{
	
}

void Args::PhysicsSystem::ResolveCollisions()
{
	std::set<uint32> entities = GetEntityList();
	std::set<uint32> correctEntities;
	for(auto entity : entities)
	{
		if(GetComponentCount<Rigidbody>(entity) && GetComponentCount<Collider>(entity))
		{
			correctEntities.insert(entity);
		}
	}

	for (auto entity : correctEntities)
	{
		
	}
}

Args::Vector3 Args::PhysicsSystem::Reflect(Vector3 surfaceNormal, Vector3 incomingVec)
{
	return (incomingVec - 2.f * dot(incomingVec, surfaceNormal) * surfaceNormal);
}



