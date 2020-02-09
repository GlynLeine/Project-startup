#include "ECS/Managers/ComponentManager.h"
#include "ECS/ComponentFamily.h"
#include "ECS/Component.h"
#include "ECS/System.h"


bool Args::ComponentManager::SetOverlaps(const std::set<uint32>& lhs, const std::set<uint32>& rhs)
{
	if (lhs.empty() || rhs.empty())
		return false;

	bool overlap = true;
	for (auto& x : rhs)
		overlap = overlap && lhs.count(x);

	return overlap;
}

void Args::ComponentManager::UpdateEntityLists()
{
	entityLists.clear();
	for (auto& systemData : *systems)
		for (auto& entityData : entities)
			if (SetOverlaps(systemData.second.get()->GetComponentRequirements(), entityData.second))
				entityLists[systemData.first].insert(entityData.first);
}

void Args::ComponentManager::UpdateEntityList(uint32 entityID)
{
	for (auto& systemData : *systems)
	{
		if (entityLists[systemData.first].count(entityID))
			entityLists[systemData.first].erase(entityID);

		if (SetOverlaps(systemData.second.get()->GetComponentRequirements(), entities[entityID]))
			entityLists[systemData.first].insert(entityID);
	}
}

uint32 Args::ComponentManager::AddComponent(std::string typeName, uint32 entityID)
{
	if (componentFamilies[typeName])
	{
		auto component = componentFamilies[typeName]->CreateComponent(entityID);
		if (component)
			UpdateEntityList(entityID);
		return component;
	}
	return 0;
}

uint32 Args::ComponentManager::CreateEntity()
{
	uint32 id = (uint32)entities.size();
	entities[id];
	return id;
}

std::set<uint32> Args::ComponentManager::GetEntityList(std::type_index systemType)
{
	return entityLists[systemType];
}
