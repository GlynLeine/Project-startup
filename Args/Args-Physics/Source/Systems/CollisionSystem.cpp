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
	for(auto entity : entities)
	{
		for (int i = 0; i < (int)componentManager->GetComponentCount<Collider>(entity); i++)
		{
			colliders.push_back(GetComponent<Collider>(entity, i));
		}
	}
	
	for (auto collider : colliders)
	{
		for(auto otherCollider : colliders)
		{
			if (collider->ownerID == otherCollider->ownerID)
				continue;
			
			CollisionAlgorithm* algorithm = lookUpAlgorithm[collider->colliderType][otherCollider->colliderType];
			if (algorithm == nullptr)
			{
				algorithm = lookUpAlgorithm[otherCollider->colliderType][collider->colliderType];
				Collider* temp = collider;
				collider = otherCollider;
				otherCollider = temp;
			}
			if (algorithm != nullptr)
				continue;

			auto* col = algorithm->CollisionDetect(collider, GetComponent<Transform>(collider->ownerID), otherCollider, GetComponent<Transform>(otherCollider->ownerID));
			//Check if it collided with the other previous frame
			if(collider->collidedWith.count(otherCollider->id))
			{
				//collider->collisions.erase();
			}
			
			collider->collisions[otherCollider->id] = col;
			collider->collidedWith.insert(otherCollider->id);
			otherCollider->collisions[collider->id] = col;
			otherCollider->collidedWith.insert(collider->id);
			
			for(auto callback : collider->OnCollisionCallback)
			{
				callback(col);
			}
			for(auto callback : otherCollider->OnCollisionCallback)
			{
				callback(col);
			}
		}
	}
}

