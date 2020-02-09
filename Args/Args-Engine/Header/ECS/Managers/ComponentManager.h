#pragma once
#include <unordered_map>
#include <set>
#include <memory>
#include <typeindex>
#include "Utils/Common.h"
#include "ECS/ComponentFamily.h"

namespace Args
{
	class IComponentFamily;
	struct IComponent;

	class ISystem;

	class ComponentManager
	{
		friend class ECS;
	private:
		std::unordered_map<std::string, std::unique_ptr<IComponentFamily>> componentFamilies;
		std::unordered_map<uint32, std::string> componentTypeIds;
		std::unordered_map<uint32, std::set<uint32>> entities;
		std::unordered_map<std::type_index, std::set<uint32>> entityLists;

		std::unordered_map<std::type_index, std::unique_ptr<ISystem>>* systems = nullptr;

		bool SetOverlaps(const std::set<uint32>& lhs, const std::set<uint32>& rhs);

		void UpdateEntityLists();

		void UpdateEntityList(uint32 entityID);

	public:
		template<typename ComponentType, INHERITS_FROM(ComponentType, IComponent)>
		void RegisterComponentType();


		template<typename ComponentType, INHERITS_FROM(ComponentType, IComponent)>
		uint32 AddComponent(uint32 entityID);

		/// <summary>
		/// Request component creation on component name.
		/// Is less reliable than the templated version since it does not check the component type on compile time.
		/// On success returns pointer to created component. Will return nullptr with unknown types.
		/// </summary>
		uint32 AddComponent(std::string typeName, uint32 entityID);

		uint32 CreateEntity();

		template<class SystemType, INHERITS_FROM(SystemType, ISystem)>
		std::set<uint32> GetEntityList();

		std::set<uint32> GetEntityList(std::type_index systemType);

		template<typename ComponentType, typename... Components>
		std::unordered_map<std::type_index, std::unordered_map<uint32, std::vector<IComponent*>>> GetComponents(char(*)[(-(int)sizeof...(Components)) + 1] = 0)
		{
			std::unordered_map<uint32, std::vector<IComponent*>> componentsPerEntity = componentFamilies[GetTypeName<ComponentType>()].get()->GetComponents();

			std::unordered_map<std::type_index, std::unordered_map<uint32, std::vector<IComponent*>>> components;

			for (auto entity : componentsPerEntity)
				for (IComponent* component : entity.second)
					components[typeid(ComponentType)][entity.first].push_back(component);

			return components;
		}

		template<typename ComponentType, typename... Components>
		std::unordered_map<std::type_index, std::unordered_map<uint32, std::vector<IComponent*>>> GetComponents(char(*)[sizeof...(Components)] = 0)
		{
			std::unordered_map<uint32, std::vector<IComponent*>> componentsPerEntity = componentFamilies[GetTypeName<ComponentType>()].get()->GetComponents();

			std::unordered_map<std::type_index, std::unordered_map<uint32, std::vector<IComponent*>>> components = GetComponents<Components...>();

			for (auto entity : componentsPerEntity)
				for (IComponent* component : entity.second)
					components[typeid(ComponentType)][entity.first].push_back(component);

			return components;
		}
	};

	template<typename ComponentType, typename>
	void ComponentManager::RegisterComponentType()
	{
		std::string typeName = GetTypeName<ComponentType>();
		uint32 id = (uint32)componentTypeIds.size() + 1;
		componentTypeIds[id] = typeName;
		componentFamilies[typeName] = std::unique_ptr<IComponentFamily>(new TypedComponentFamily<ComponentType>(id));

		Debug::Log(DebugInfo, "Registered component type: %s\n", typeName.c_str());
	}

	template<typename ComponentType, typename>
	uint32 ComponentManager::AddComponent(uint32 entityID)
	{
		std::string typeName = GetTypeName<ComponentType>();
		return AddComponent(typeName, entityID);
	}

	template<class SystemType, typename>
	std::set<uint32> ComponentManager::GetEntityList()
	{
		return entityLists[typeid(SystemType)];
	}
	
}