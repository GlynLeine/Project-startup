#pragma once
#include <unordered_map>
#include <memory>
#include "Utils/Common.h"

namespace Args
{
	class IComponentFamily;
	struct IComponent;

	class ComponentManager
	{
	private:
		std::unordered_map<std::string, std::unique_ptr<IComponentFamily>> componentFamilies;
		std::unordered_map<uint32, std::string> componentTypeIds;

	public:
		template<typename ComponentType, INHERITS_FROM(ComponentType, IComponent)>
		void RegisterComponentType();


		template<typename ComponentType, INHERITS_FROM(ComponentType, IComponent)>
		ComponentType* CreateComponent(uint32 entityID);

		/// <summary>
		/// Request component creation on component name.
		/// Is less reliable than the templated version since it does not check the component type on compile time.
		/// On success returns pointer to created component. Will return nullptr with unknown types.
		/// </summary>
		IComponent* CreateComponent(std::string typeName, uint32 entityID);
	};

	template<typename ComponentType, typename>
	void ComponentManager::RegisterComponentType()
	{
		std::string typeName = GetTypeName<ComponentType>();
		uint32 id = (uint32)componentTypeIds.size()+1;
		componentTypeIds[id] = typeName;
		componentFamilies[typeName] = std::unique_ptr<IComponentFamily>(new TypedComponentFamily<ComponentType>(id));

		Debug::Log(DebugInfo, "Registered component type: %s\n", typeName.c_str());
	}

	template<typename ComponentType, typename>
	ComponentType* ComponentManager::CreateComponent(uint32 entityID)
	{
		std::string typeName = GetTypeName<ComponentType>();
		return dynamic_cast<ComponentType*>(CreateComponent(typeName, entityID));
	}
}