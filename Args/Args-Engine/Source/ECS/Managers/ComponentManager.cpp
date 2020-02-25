#include "ECS/Managers/ComponentManager.h"
#include "ECS/ComponentFamily.h"
#include "ECS/Component.h"
#include "ECS/System.h"


bool Args::ComponentManager::SetOverlaps(const std::set<uint32>& systemRequirements, const std::set<uint32>& entityComponents)
{
	if (systemRequirements.empty() || entityComponents.empty() || entityComponents.size() < systemRequirements.size())
		return false;

	bool overlap = true;
	for (auto& x : systemRequirements)
		overlap = overlap && entityComponents.count(x);

	return overlap;
}

void Args::ComponentManager::UpdateEntityList(uint32 entityID, uint32 componentTypeId)
{
	if (systems)
		for (auto& systemData : *systems)
		{
			if (!systemData.second.get()->GetComponentRequirements().count(componentTypeId))
				continue;

			if (entityLists[systemData.first].count(entityID))
				entityLists[systemData.first].erase(entityID);

			if (SetOverlaps(systemData.second.get()->GetComponentRequirements(), entities[entityID]))
				entityLists[systemData.first].insert(entityID);
		}
}

size_t Args::ComponentManager::GetEntityCount()
{
	return entities.size();
}

Args::uint32 Args::ComponentManager::AddComponent(std::string typeName, Args::uint32 entityID)
{
	if (componentFamilies[typeName])
	{
		auto componentID = componentFamilies[typeName]->CreateComponent(entityID);
		if (componentID)
		{
			uint32 typeId = componentFamilies[typeName]->GetComponentTypeID(componentID);
			entities[entityID].insert(typeId);
			UpdateEntityList(entityID, typeId);
		}
		return componentID;
	}
	return 0;
}

Args::uint32 Args::ComponentManager::CreateEntity()
{
	uint32 id = (uint32)entities.size() + 1;
	entities[id];

	//Debug::Log(DebugInfo, "Created entity with id %u", id);
	return id;
}

void Args::ComponentManager::DestroyEntity(uint32 entityId)
{

}

std::set<Args::uint32> Args::ComponentManager::GetEntityList(std::type_index systemType)
{
	return entityLists[systemType];
}
