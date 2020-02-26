#include <Systems/CollisionSystem.h>
#include "Helpers/AABB_AABB.h"
#include "Helpers/AABB_Sphere.h"
#include "Helpers/Sphere_Sphere.h"
#include <ECS/Managers/ComponentManager.h>
#include <algorithm>

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


void Args::CollisionSystem::updateColliders()
{
	entities.clear();
	colliders.clear();
	entities = GetEntityList();
	for (auto entity : entities)
	{
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
			if (algorithm == nullptr)
			{
				algorithm = lookUpAlgorithm[otherCollider->colliderType][collider->colliderType];
				Collider* temp = collider;
				collider = otherCollider;
				otherCollider = temp;
			}
			//If all else fails and it can't find something. QUIT lyfe
			if (algorithm == nullptr)
				continue;

			//check collision
			auto* col = algorithm->CollisionDetect(collider, GetComponent<Transform>(collider->ownerID), otherCollider, GetComponent<Transform>(otherCollider->ownerID));

			//Check if already collided. If so, remove it
			if (col == nullptr)
			{
				if (collider->collidedWith.count(otherCollider->id))
				{
					//OnTriggerEnd
					for (auto callback : collider->OnCollisionStayCallback)
					{
						callback(collider->collisions[otherCollider->id]);
					}
					for (auto callback : collider->OnCollisionStayCallback)
					{
						callback(collider->collisions[collider->id]);
					}

					collider->collisions.erase(otherCollider->id);
					collider->collidedWith.erase(otherCollider->id);
					otherCollider->collisions.erase(collider->id);
					otherCollider->collidedWith.erase(collider->id);
				}
				continue;
			}
			
			if (collider->collidedWith.count(otherCollider->id))
			{
				//OnTriggerStay
				for (auto callback : collider->OnCollisionStayCallback)
				{
					callback(col);
				}
				for (auto callback : collider->OnCollisionStayCallback)
				{
					callback(col);
				}
				collider->collisions.erase(otherCollider->id);
				collider->collidedWith.erase(otherCollider->id);
				otherCollider->collisions.erase(collider->id);
				otherCollider->collidedWith.erase(collider->id);
			}
			
			//Fill in collision list
			collider->collisions[otherCollider->id] = col;
			collider->collidedWith.insert(otherCollider->id);
			otherCollider->collisions[collider->id] = col;
			otherCollider->collidedWith.insert(collider->id);
			
			//OnCollisionEnter
			for (auto callback : collider->OnCollisionCallback)
			{
				callback(col);
			}
			for (auto callback : otherCollider->OnCollisionCallback)
			{
				callback(col);
			}
		}
	}
}

