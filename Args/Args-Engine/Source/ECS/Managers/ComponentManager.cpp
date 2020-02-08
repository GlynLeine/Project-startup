#include "ECS/Managers/ComponentManager.h"
#include "ECS/ComponentFamily.h"
#include "ECS/Component.h"


Args::IComponent* Args::ComponentManager::CreateComponent(std::string typeName, uint32 entityID)
{
	if (componentFamilies[typeName])
		return componentFamilies[typeName]->CreateComponent(entityID);
	return nullptr;
}
