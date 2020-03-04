#include <Systems/PhysicsSystem.h>
#include <Components/Collider.h>
#include <Collision.h>

void Args::PhysicsSystem::Init()
{
	BindForFixedUpdate((1.f / 80.f), std::bind(&PhysicsSystem::ResolveCollisions, this, std::placeholders::_1));
	Debug::Success(DebugInfo, "Initialised PhysicsSystem");
}



void Args::PhysicsSystem::ResolveCollisions(float deltaTime)
{
	std::set<uint32> entities = GetEntityList();

	//Collision Resolution
	for (auto entity : entities)
	{
		//Getting colliders per entity
		std::vector<Collider*> colliders = GetComponentsOfType<Collider>(entity);

		//get rigidbody
		Rigidbody* rigidbody = GetComponent<Rigidbody>(entity);
		Transform* transform = GetComponent<Transform>(entity);

		//calculate reflect
		for (auto collider : colliders)
		{
			if (collider->isTrigger) continue;
			for (auto collision : collider->collisions)
			{
				Debug::Log(DebugInfo, "Resolving Collision for collider %i", collider->id);
				Debug::Log(DebugInfo, "Normal %f %f %f", collision.second.normal.x, collision.second.normal.y, collision.second.normal.z);
				rigidbody->impulses.push_back(Bounce(collision.second.normal, rigidbody->velocity, 0.8f));
				transform->position += Bounce(collision.second.normal, rigidbody->velocity * (1.f / 80.f), 0.f);
			}
		}

		for (auto force : rigidbody->forces)
			rigidbody->velocity += force * (1.f / 80.f);

		for (auto impulse : rigidbody->impulses)
			rigidbody->velocity += impulse;

		//Debug::Log(DebugInfo, "Velocity: %f %f %f", rigidbody->velocity.x, rigidbody->velocity.y, rigidbody->velocity.z);
		rigidbody->impulses.clear();

		transform->position += rigidbody->velocity * (1.f / 80.f);

		//Debug::Log(DebugInfo, "Position: %f %f %f", transform->position.x, transform->position.y, transform->position.z);

	}
}

Args::Vector3 Args::PhysicsSystem::Bounce(Vector3 surfaceNormal, Vector3 incomingVec, float restitution)
{
	Vector3 result = -(1 + restitution) * dot(incomingVec, surfaceNormal) * surfaceNormal;
	Debug::Log(DebugInfo, "Bounce %f %f %f", result.x, result.y, result.z);
	return result;
}



