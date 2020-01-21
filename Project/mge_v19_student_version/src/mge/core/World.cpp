#include <iostream>
#include <algorithm>

#include "mge/core/World.hpp"
#include "mge/lights/Light.h"
#include "mge/config.hpp"

World::World():GameObject("root"), _mainCamera(0), objectCount(0), batchCount(0)
{
	_world = this;
}

void World::setMainCamera (Camera* pCamera) {
    if (pCamera != NULL) _mainCamera = pCamera;
}

Camera* World::getMainCamera () {
    return _mainCamera;
}

void World::registerLight (Light* pLight) {
	if (_lights.size() >= config::MAX_LIGHT_COUNT)
	{
		//std::cout << "Did not register light " << pLight->getName() << ", max light count reached!" << std::endl;
		return;
	}

    //std::cout << "Registering light " << pLight->getName() << std::endl;
    _lights.push_back(pLight);
}

void World::unregisterLight (Light* pLight) {
    //std::cout << "Unregistering light " << pLight->getName() << std::endl;
	if (_lights.size() == 0) return;
    _lights.erase(std::remove(_lights.begin(), _lights.end(), pLight), _lights.end());
}

Light* World::getLightAt (int pIndex) {
    return _lights[pIndex];
}

int World::getLightCount() {
    return _lights.size();
}

void World::add(GameObject * obj)
{
	GameObject::add(obj);
	batches[obj->getMesh()][obj->getMaterial()].push_back(obj);

	objectCount++;

	if (batches[obj->getMesh()][obj->getMaterial()].size() == 1)
		batchCount++;
}

void World::remove(GameObject * obj)
{
	GameObject::remove(obj);
	std::vector<GameObject*>* instances = &batches[obj->getMesh()][obj->getMaterial()];
	instances->erase(std::remove(instances->begin(), instances->end(), obj), instances->end());

	objectCount--;

	if (batches[obj->getMesh()][obj->getMaterial()].size() == 0)
		batchCount--;
}

std::unordered_map<Mesh*, std::unordered_map<AbstractMaterial*, std::vector<GameObject*>>> World::getRenderBatches()
{
	return batches;
}

unsigned World::GetBatchCount()
{
	return batchCount;
}

unsigned World::GetObjectCount()
{
	return objectCount;
}
