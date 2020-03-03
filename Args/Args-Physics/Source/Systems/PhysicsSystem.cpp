#include <Systems/PhysicsSystem.h>
#include <Components/Collider.h>
#include <Collision.h>

void Args::PhysicsSystem::Init()
{
	BindForFixedUpdate((1.f/60.f), std::bind(&PhysicsSystem::ResolveCollisions, this, std::placeholders::_1));
	Debug::Success(DebugInfo, "Initialised TestSystem");
}



void Args::PhysicsSystem::ResolveCollisions(float deltaTime)
{
	std::set<uint32> entities = GetEntityList();

	//Collision Resolution
	for (auto entity : entities)
	{
		//Getting colliders per entity
		std::vector<Collider*> colliders;
		for(int i = 0; i < GetComponentCount<Collider>(entity);i++)
		{
			colliders.push_back(GetComponent<Collider>(entity, i));
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
		rigidbody->forces.push_back(Vector3(0, -0.981f, 0));

		for(auto force : rigidbody->forces)
		{
			rigidbody->velocity += force * (1.f / 60.f);
		}
		
		Debug::Log(DebugInfo, "Velocity: %f %f %f", rigidbody->velocity.x, rigidbody->velocity.y, rigidbody->velocity.z);
		rigidbody->forces.clear();

		Transform* transform = GetComponent<Transform>(entity);
		transform->position += rigidbody->velocity * (1.f / 60.f);

		Debug::Log(DebugInfo, "Position: %f %f %f", transform->position.x, transform->position.y, transform->position.z);

	}
}

Args::Vector3 Args::PhysicsSystem::Reflect(Vector3 surfaceNormal, Vector3 incomingVec,float bounciness)
{
	return (incomingVec - (1+bounciness) * dot(incomingVec, surfaceNormal) * surfaceNormal);
}



