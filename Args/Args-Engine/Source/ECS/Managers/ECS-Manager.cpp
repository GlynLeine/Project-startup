#include "ECS/Managers/ECS-Manager.h"

Args::ECSManager::ECSManager() : componentManager()
{
}

uint32 Args::ECSManager::CreateEntity()
{
	uint32 id = (uint32)entities.size() + 1;
	entities[id] = std::make_unique<Entity>(id);

	Debug::Log(DebugInfo, "Created entity with id %u", id);
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
