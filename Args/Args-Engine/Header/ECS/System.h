#pragma once

#include <memory>
#include <array>
#include <set>
#include <functional>
#include "Utils/Common.h"
#include "ECS/Component.h"
#include "ECS/Managers/ComponentManager.h"

namespace Args
{
	class ISystem
	{
		friend class SystemManager;
		friend class std::unique_ptr<ISystem>;

	private:
		bool enabled = true;

	protected:
		ComponentManager* componentManager = nullptr;

		std::vector<std::tuple<float, float, std::function<void(float)>>> updateCallbacks;

	public:
		virtual void Init() = 0;
		virtual void UpdateEntities(float deltaTime) = 0;
		virtual std::set<uint32> GetComponentRequirements() = 0;

		template<typename ComponentType>
		ComponentType* GetStaticComponent();

		bool Enable(bool enabled) { this->enabled = enabled; }
	};

	template<typename ComponentType>
	inline ComponentType* ISystem::GetStaticComponent()
	{
		return componentManager->GetStaticComponent<ComponentType>();
	}

#pragma region Typed System without components
	template<class Self>
	class GlobalSystem : public ISystem
	{
	public:
		virtual std::set<uint32> GetComponentRequirements() override
		{	return std::set<uint32>();	}

	protected:

		void BindForUpdate(std::function<void(float)> func)
		{	updateCallbacks.push_back(std::make_tuple(0.f, 0.f, func));	}

		void BindForFixedUpdate(float interval, std::function<void(float)> func)
		{	updateCallbacks.push_back(std::make_tuple(interval, 0.f, func));	}

		GlobalSystem() {};

		virtual void UpdateEntities(float deltaTime) override
		{
			for (auto& [interval, timeBuffer, function] : updateCallbacks)
			{
				if (interval == 0.f)
				{
					function(deltaTime);

					continue;
				}

				timeBuffer += deltaTime;

				while (timeBuffer >= interval)
				{
					timeBuffer -= interval;

					function(interval);
				}
			}
		}
	};
#pragma endregion


#pragma region Typed System with components
	template<class Self, class... Components>
	class System : public ISystem
	{
	private:
		static std::set<uint32> componentRequirements;

		std::unordered_map<std::type_index, std::unordered_map<uint32, std::vector<IComponent*>>> components;

		template<class ComponentType, class... ComponentTypes>
		void GetComponentsInternal(std::unordered_map<std::type_index, uint32>& typeCount, ComponentType** component, ComponentTypes**... components);

		template<class ComponentType>
		void GetComponentsInternal(std::unordered_map<std::type_index, uint32>& typeCount, ComponentType** component);

	public:
		virtual std::set<uint32> GetComponentRequirements() override;

	protected:

		void GetComponents(Components**... components);

		void BindForUpdate(std::function<void(float)> func);
		void BindForFixedUpdate(float interval, std::function<void(float)> func);

		uint32 currentEntityID = 1;

		System();

		virtual void UpdateEntities(float deltaTime) override;
	};

	template<class Self, class... Components>
	std::set<uint32> System<Self, Components...>::componentRequirements;

	template<class Self, class... Components>
	System<Self, Components...>::System()
	{
		static_assert((std::is_base_of_v<IComponent, Components> || ...), "One of the passed components doesn't inherit from Component.");

		(componentRequirements.insert(Components::typeId), ...);
	}

	template<class Self, class ...Components>
	void System<Self, Components...>::UpdateEntities(float deltaTime)
	{
		this->components = componentManager->GetComponents<Components...>();
		std::set<uint32> entities = componentManager->GetEntityList<Self>();

		for (auto& [interval, timeBuffer, function] : updateCallbacks)
		{
			if (interval == 0.f)
			{
				for (uint32 entityId : entities)
				{
					currentEntityID = entityId;
					function(deltaTime);
				}

				continue;
			}

			timeBuffer += deltaTime;

			while (timeBuffer >= interval)
			{
				timeBuffer -= interval;

				for (uint32 entityId : entities)
				{
					currentEntityID = entityId;
					function(interval);
				}
			}
		}
	}

	template<class Self, class ...Components>
	inline std::set<uint32> System<Self, Components...>::GetComponentRequirements()
	{
		return componentRequirements;
	}

	template<class Self, class ...Components>
	void System<Self, Components...>::GetComponents(Components**... components)
	{
		std::unordered_map<std::type_index, uint32> typeCount;

		GetComponentsInternal(typeCount, components...);
	}

	template<class Self, class ...Components>
	void System<Self, Components...>::BindForUpdate(std::function<void(float)> func)
	{
		updateCallbacks.push_back(std::make_tuple(0.f, 0.f, func));
	}

	template<class Self, class ...Components>
	void System<Self, Components...>::BindForFixedUpdate(float interval, std::function<void(float)> func)
	{
		updateCallbacks.push_back(std::make_tuple(interval, 0.f, func));
	}


	template<class Self, class ...Components>
	template<class ComponentType, class ...ComponentTypes>
	inline void System<Self, Components...>::GetComponentsInternal(std::unordered_map<std::type_index, uint32>& typeCount, ComponentType** component, ComponentTypes** ...components)
	{
		*component = dynamic_cast<ComponentType*>(this->components[typeid(ComponentType)][currentEntityID][typeCount[typeid(ComponentType)]]);
		typeCount[typeid(ComponentType)]++;

		GetComponentsInternal(typeCount, components...);
	}

	template<class Self, class ...Components>
	template<class ComponentType>
	inline void System<Self, Components...>::GetComponentsInternal(std::unordered_map<std::type_index, uint32>& typeCount, ComponentType** component)
	{
		*component = dynamic_cast<ComponentType*>(this->components[typeid(ComponentType)][currentEntityID][typeCount[typeid(ComponentType)]]);
		typeCount[typeid(ComponentType)]++;
	}
#pragma endregion

}
