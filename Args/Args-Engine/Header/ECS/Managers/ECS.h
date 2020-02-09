#pragma once
#include "ComponentManager.h"
#include "SystemManager.h"

namespace Args
{
	class ECS
	{
	private:
		ComponentManager componentManager;
		SystemManager systemManager;
	public:

		ECS() : componentManager(), systemManager()
		{
			componentManager.systems = &(systemManager.systems);
		}


		template<class ComponentType, INHERITS_FROM(ComponentType, IComponent)>
		uint32 AddComponent(uint32 entityId);

		uint32 CreateEntity();

		template<class SystemType, INHERITS_FROM(SystemType, ISystem)>
		void RegisterSystem(uint32 priority = 999);

		template<typename ComponentType, INHERITS_FROM(ComponentType, IComponent)>
		void RegisterComponentType();

		template<class ComponentType, class... Components>
		std::unordered_map<uint32, std::tuple<ComponentType, Components...>> GetComponentCombination();

		void InitialiseSystems();

		void UpdateSystems();

		template<class SystemType, INHERITS_FROM(SystemType, ISystem)>
		static void EnableSystem(bool enabled);
	};


	template<typename ComponentType, typename>
	inline uint32 ECS::AddComponent(uint32 entityId)
	{
		return componentManager.AddComponent<ComponentType>(entityId);
	}

	template<class SystemType, typename>
	inline void ECS::RegisterSystem(uint32 priority)
	{
		systemManager.RegisterSystem<SystemType>(&componentManager, priority);
	}

	template<typename ComponentType, typename>
	inline void ECS::RegisterComponentType()
	{
		componentManager.RegisterComponentType<ComponentType>();
	}

	template<class ComponentType, class ...Components>
	inline std::unordered_map<uint32, std::tuple<ComponentType, Components...>> ECS::GetComponentCombination()
	{
		return componentManager.GetComponentCombination<ComponentType, Components...>();
	}

	template<class SystemType, typename>
	inline void ECS::EnableSystem(bool enabled)
	{
		systemManager.EnableSystem<SystemType>();
	}
}
