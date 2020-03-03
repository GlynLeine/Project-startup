#include <Systems/CollisionSystem.h>
#include "Helpers/AABB_AABB.h"
#include "Helpers/AABB_Sphere.h"
#include "Helpers/Sphere_Sphere.h"
#include <ECS/Managers/ComponentManager.h>
#include <algorithm>


void Args::CollisionSystem::Init()
{
	BindForUpdate(std::bind(&CollisionSystem::UpdateColliders, this, std::placeholders::_1));

	Debug::Success(DebugInfo, "Initialised CollisionSystem");
}

Args::CollisionSystem::CollisionSystem()
{
	lookUpAlgorithm[0][0] = new AABB_AABB();
	lookUpAlgorithm[0][1] = new AABB_Sphere();
	lookUpAlgorithm[1][1] = new Sphere_Sphere();
}

Args::CollisionSystem::~CollisionSystem()
{
	delete lookUpAlgorithm[0][0], lookUpAlgorithm[0][1], lookUpAlgorithm[1][1];
}


void Args::CollisionSystem::UpdateColliders(float deltaTime)
{
	std::vector<Collider*> colliders;
	std::unordered_map<uint32, Transform*> transforms;
	auto entities = GetEntityList();
	for (auto entity : entities)
	{
		transforms[entity] = GetComponent<Transform>(entity);
		for (int i = 0; i < (int)GetComponentCount<Collider>(entity); i++)
		{
			colliders.push_back(GetComponent<Collider>(entity, i));
		}
	}

	for (auto collider : colliders)
	{
		for (auto otherCollider : colliders)
		{
			//Check to not collision check itself
			if (collider->ownerID == otherCollider->ownerID)
				continue;

			//Try and find an algorithm for checking
			CollisionAlgorithm* algorithm = lookUpAlgorithm[collider->colliderType][otherCollider->colliderType];
			//If it doesn't find one, try by switching the 2 around
			if (!algorithm)
			{
				algorithm = lookUpAlgorithm[otherCollider->colliderType][collider->colliderType];

				if (!algorithm)
					continue;

				Collider* temp = collider;
				collider = otherCollider;
				otherCollider = temp;
			}

			//check collision
			Collision collision = algorithm->CollisionDetect(collider, GetComponent<Transform>(collider->ownerID), otherCollider, GetComponent<Transform>(otherCollider->ownerID));

			//Check if already collided. If so, remove it
			if (!collision)
			{
				if (collider->collidedWith.count(otherCollider->id))
				{
					//OnTriggerEnd
					for (auto callback : collider->OnCollisionEndCallback)
					{
						callback(collider->collisions[otherCollider->id]);
					}

					collider->collisions.erase(otherCollider->id);
					collider->collidedWith.erase(otherCollider->id);
				}
				continue;
			}
			
			// collided before
			if (collider->collidedWith.count(otherCollider->id))
			{
				//OnTriggerStay
				for (auto callback : collider->OnCollisionStayCallback)
				{
					callback(collision);
				}
				
				collider->collisions[otherCollider->id] = collision;
				continue;
			}
			
			//Fill in collision list
			collider->collisions[otherCollider->id] = collision;
			collider->collidedWith.insert(otherCollider->id);
			
			//OnCollisionEnter
			for (auto callback : collider->OnCollisionCallback)
			{
				callback(collision);
			}
		}
	}
}

