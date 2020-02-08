#pragma once

#include <memory>
#include <set>
#include <functional>
#include "Utils/Common.h"
#include "ECS/Component.h"
#include "Engine/BaseComponents.h"

namespace Args
{
	class ISystem
	{
		friend class ECSManager;
		friend class std::unique_ptr<ISystem>;

	private:
		bool enabled = true;

	protected:
		ECSManager* manager;

	public:
		virtual void Init() = 0;
		bool Enable(bool enabled) { this->enabled = enabled; }
	};

	template<class Self, class ComponentType, class... Components>
	class System : public ISystem
	{
	private:
		static std::set<uint32> componentRequirements;

	public:
		static uint32 SYSTEM_ID;
		static uint32 COMPONENT_IDS[];

	protected:

		void GetComponents(ComponentType*& component, Components*&... components);

		void BindForUpdate(UpdateFunc<Self> func);

		uint32 currentEntityID = 1;

		System(Self* self);
	};

	template<class Self, class ComponentType, class... Components>
	std::set<uint32> System<Self, ComponentType, Components...>::componentRequirements = nullptr;

	template<class Self, class ComponentType, class... Components>
	uint32 System<Self, ComponentType, Components...>::SYSTEM_ID = typeid(Self).hash_code();

	template<class Self, class ComponentType, class... Components>
	uint32 System<Self, ComponentType, Components...>::COMPONENT_IDS[sizeof...(Components)];

	template<class Self, class ComponentType, class... Components>
	System<Self, ComponentType, Components...>::System(Self* self)
	{
		static_assert(std::is_base_of_v<IComponent, ComponentType> || (std::is_base_of_v<IComponent, Components> || ...), "One of the passed components doesn't inherit from Component.");
	}

	template<class Self, class ComponentType, class ...Components>
	void System<Self, ComponentType, Components...>::GetComponents(ComponentType*& component, Components*&... components)
	{
		manager->GetComponents(currentEntityID, component, components...);
	}
	template<class Self, class ComponentType, class ...Components>
	inline void System<Self, ComponentType, Components...>::BindForUpdate(UpdateFunc<Self> func)
	{
		manager->BindForUpdate<Self>(func);
	}
}
