#include <Systems/CollisionSystem.h>
#include "Helpers/AABB_AABB.h"
#include "Helpers/AABB_Sphere.h"
#include "Helpers/Sphere_Sphere.h"
#include <ECS/Managers/ComponentManager.h>

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
	entities = GetEntityList();
	//for (int i = 0; i < GetComponent)
	//colliders = GetComponent<Collider>(entities,Get);
}

