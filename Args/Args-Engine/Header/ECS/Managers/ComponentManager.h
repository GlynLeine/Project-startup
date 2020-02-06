#pragma once
#include <ECS/ComponentFamily.h>
#include <unordered_map>

namespace Args
{
	class ComponentManager
	{
	private:
		static int familyCount;

		static std::unordered_map<std::string, std::unique_ptr<IComponentFamily>> componentFamilies;
		static std::unordered_map<uint32, std::string> componentTypeIds;

	public:
		template<typename ComponentType, INHERITS_FROM(ComponentType, IComponent)>
		static void RegisterComponentType();

		template<typename ComponentType, INHERITS_FROM(ComponentType, IComponent)>
		static ComponentType* CreateComponent(uint32 entityID);

		static IComponent* CreateComponent(std::string typeName, uint32 entityID)
		{
			if (componentFamilies[typeName])
				return componentFamilies[typeName]->CreateComponent(entityID);
			return nullptr;
		}
	};

	template<typename ComponentType, typename>
	void ComponentManager::RegisterComponentType()
	{
		std::string typeName = GetTypeName<ComponentType>();
		uint32 id = componentTypeIds.size()+1;
		componentTypeIds[id] = typeName;
		componentFamilies[typeName] = std::unique_ptr<IComponentFamily>(new TypedComponentFamily<ComponentType>(id));

		Debug::Log("Registered component type: %s\n", typeName.c_str());
	}

	template<typename ComponentType, typename>
	ComponentType* ComponentManager::CreateComponent(uint32 entityID)
	{
		std::string typeName = GetTypeName<ComponentType>();
		return dynamic_cast<ComponentType*>(CreateComponent(typeName, entityID));
	}
}