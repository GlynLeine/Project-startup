#include "ECS/Managers/SystemManager.h"

Args::SystemManager::SystemManager()
{
}


Args::ISystem* Args::SystemManager::GetSystem(std::type_index systemType)
{
	return systems[systemType].get();
}

std::vector<Args::ISystem*> Args::SystemManager::GetSystems()
{
	std::vector<ISystem*> ret;

	for (auto& systemData : systems)
		ret.push_back(systemData.second.get());

	return ret;
}

void Args::SystemManager::InitialiseSystems()
{
	for (auto priorityData : systemPriorities)
		for (auto systemType : priorityData.second)
			systems[systemType]->Init();
}

void Args::SystemManager::UpdateSystems()
{
	for (auto priorityData : systemPriorities)
		for (auto systemType : priorityData.second)
			systems[systemType]->UpdateEntities(1.f/ 60.f);
}
