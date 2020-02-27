#include <Systems/PhysicsSystem.h>
#include <Components/Collider.h>
#include <Collision.h>

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
	//Collision Resolution
	for (auto entity : correctEntities)
	{
		//Getting colliders per entity
		std::vector<Collider*> colliders;
		for(int i = 0; i < GetComponentCount<Collider>(entity);i++)
		{
			colliders.push_back(GetComponent<Collider>(entity, 1));
		}

		//get rigidbody
		Rigidbody* rigidbody = GetComponent<Rigidbody>(entity);

		//calculate reflect
		for(auto collider : colliders)
		{
			if (collider->isTrigger) continue;
			for (auto collision : collider->collisions)
			{
				rigidbody->forces.push_back(Reflect(collision.second->normal, rigidbody->velocity,0.4f));
			}
		}

		//Gravity
		rigidbody->forces.push_back(Vector3(0, -9.81f, 0));

		for(auto force : rigidbody->forces)
		{
			rigidbody->velocity += force;
		}

		rigidbody->forces.clear();
	}
}

glm::Vector3 Args::PhysicsSystem::Reflect(Vector3 surfaceNormal, Vector3 incomingVec,float bounciness)
{
	return (incomingVec - (1+bounciness) * dot(incomingVec, surfaceNormal) * surfaceNormal);
}



