#include "ECS/Managers/ECS-Manager.h"

uint32 Args::ECSManager::CreateEntity()
{
	uint32 id = entities.size();
	entities[id] = std::make_unique<Entity>(id);

	Debug::Log("Created entity with id " + std::to_string(id));
	return id;
}


void Args::ECSManager::InitialiseSystems()
{
	for (auto priorityData : systemPriorities)
		for (auto systemType : priorityData.second)
			systems[systemType]->Init();
}

void Args::ECSManager::UpdateSystems()
{
	for (auto priorityData : systemPriorities)
		for (auto systemType : priorityData.second)
			if (updateCallbacks[systemType])
				updateCallbacks[systemType](1.f / 60.f);
}
