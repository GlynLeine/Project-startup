#pragma once
#include <vector>
#include <tuple>
#include <unordered_map>
#include <map>
#include <type_traits>
#include <typeindex>
#include <memory>
#include <functional>

#include "Utils/Common.h"
#include "ECS/Component.h"
#include "ECS/System.h"
#include "ECS/Entity.h"
#include "ECS/ComponentFamily.h"
#include "ComponentManager.h"

namespace Args
{
	class ECSManager
	{
	private:
		std::unordered_map<std::type_index, std::function<void(float)>> updateCallbacks;

		std::unordered_map<std::type_index, std::unique_ptr<ISystem>> systems;
		std::map<uint32, std::vector<std::type_index>> systemPriorities;

		std::unordered_map<uint32, std::unique_ptr<Entity>> entities;

	public:
		template<class ComponentType, INHERITS_FROM(ComponentType, IComponent)>
		ComponentType* AddComponent(uint32 entityId);

		uint32 CreateEntity();

		template<class SystemType, INHERITS_FROM(SystemType, ISystem)>
		void RegisterSystem(uint32 priority = 999);

		template<typename ComponentType, INHERITS_FROM(ComponentType, IComponent)>
		void RegisterComponentType();

		template<class ComponentType, class... Components>
		void GetComponents(uint32 entityID, ComponentType*& component, Components*&... components);

		template<class SystemType, INHERITS_FROM(SystemType, ISystem)>
		void BindForUpdate(UpdateFunc<SystemType> func);

		void InitialiseSystems();

		void UpdateSystems();

		template<class SystemType, INHERITS_FROM(SystemType, ISystem)>
		static void EnableSystem(bool enabled);
	};

	template<class ComponentType, typename>
	ComponentType* ECSManager::AddComponent(uint32 entityId)
	{
		ComponentType* component = ComponentManager::CreateComponent<ComponentType>(entityId);

		if (component)
		{
			entities[entityId]->components[typeid(ComponentType)].push_back(component);
			entities[entityId]->containedComponents.insert(ComponentType::id);
		}
		return component;
	}

	template<class SystemType, typename>
	void ECSManager::RegisterSystem(uint32 priority)
	{
		systems[typeid(SystemType)] = std::unique_ptr<ISystem>(new SystemType());
		systems[typeid(SystemType)]->manager = this;
		systemPriorities[priority].push_back(typeid(SystemType));
		Debug::Log("Registered system of type: %s\n", GetTypeName<SystemType>().c_str());
	}

	template<typename ComponentType, typename>
	void ECSManager::RegisterComponentType()
	{
		ComponentManager::RegisterComponentType<ComponentType>();
	}

	template<class ComponentType, class ...Components>
	void ECSManager::GetComponents(uint32 entityID, ComponentType*& component, Components*&... components)
	{
		static_assert(std::is_base_of_v<IComponent, ComponentType>, "One of the passed components doesn't inherit from Component.");

		entities[entityID]->GetComponents(component, components...);
	}

	template<class SystemType, typename>
	inline void ECSManager::BindForUpdate(UpdateFunc<SystemType> func)
	{
		auto function = std::bind(func, dynamic_cast<SystemType*>(systems[typeid(SystemType)].get()), std::placeholders::_1);
		updateCallbacks[typeid(SystemType)] = function;
	}

	template<class SystemType, typename>
	void ECSManager::EnableSystem(bool enabled)
	{
		systems[typeid(SystemType)]->Enable(enabled);
	}
}