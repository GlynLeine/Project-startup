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

		virtual void BindForUpdate(std::function<void(float)> func) = 0;
		virtual void BindForFixedUpdate(float interval, std::function<void(float)> func) = 0;

	public:
		virtual void Init() = 0;
		virtual void UpdateSystem(float deltaTime) = 0;
		virtual std::set<uint32> GetComponentRequirements() = 0;

		template<typename ComponentType>
		ComponentType* GetStaticComponent();

		bool Enable(bool enabled) { this->enabled = enabled; }
	};

	template<typename ComponentType>
	inline ComponentType* ISystem::GetStaticComponent()
	{
		return componentManager->GetGlobalComponent<ComponentType>();
	}

#pragma region Typed System without components
	template<class Self>
	class MonoUpdateSystem : public ISystem
	{
	public:
		virtual std::set<uint32> GetComponentRequirements() override
		{	return std::set<uint32>();	}

	protected:

		virtual void BindForUpdate(std::function<void(float)> func) override
		{	updateCallbacks.push_back(std::make_tuple(0.f, 0.f, func));	}

		virtual void BindForFixedUpdate(float interval, std::function<void(float)> func) override
		{	updateCallbacks.push_back(std::make_tuple(interval, 0.f, func));	}

		MonoUpdateSystem() {};

		virtual void UpdateSystem(float deltaTime) override
		{
			for (auto& [interval, timeBuffer, function] : updateCallbacks)
			{
				if (interval <= 0.001f)
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
	class EntitySystem : public ISystem
	{
	private:
		static std::set<uint32> componentRequirements;

		template<class ComponentType, class... ComponentTypes>
		void GetComponentsInternal(std::unordered_map<std::type_index, uint32>& typeCount, ComponentType** component, ComponentTypes**... components);

		template<class ComponentType>
		void GetComponentsInternal(std::unordered_map<std::type_index, uint32>& typeCount, ComponentType** component);

	public:
		virtual std::set<uint32> GetComponentRequirements() override;

	protected:

		void GetComponents(Components**... components);

		virtual void BindForUpdate(std::function<void(float)> func) override;
		virtual void BindForFixedUpdate(float interval, std::function<void(float)> func) override;

		uint32 currentEntityID = 0;

		EntitySystem();

		virtual void UpdateSystem(float deltaTime) override;
	};

	template<class Self, class... Components>
	std::set<uint32> EntitySystem<Self, Components...>::componentRequirements;

	template<class Self, class... Components>
	EntitySystem<Self, Components...>::EntitySystem()
	{
		static_assert((std::is_base_of_v<IComponent, Components> || ...), "One of the passed components doesn't inherit from Component.");

		(componentRequirements.insert(Components::typeId), ...);
	}

	template<class Self, class ...Components>
	void EntitySystem<Self, Components...>::UpdateSystem(float deltaTime)
	{
		std::set<uint32> entities = componentManager->GetEntityList<Self>();

		for (auto& [interval, timeBuffer, function] : updateCallbacks)
		{
			if (interval <= 0.001f)
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
	inline std::set<uint32> EntitySystem<Self, Components...>::GetComponentRequirements()
	{
		return componentRequirements;
	}

	template<class Self, class ...Components>
	void EntitySystem<Self, Components...>::GetComponents(Components**... components)
	{
		std::unordered_map<std::type_index, uint32> typeCount;

		GetComponentsInternal(typeCount, components...);
	}

	template<class Self, class ...Components>
	void EntitySystem<Self, Components...>::BindForUpdate(std::function<void(float)> func)
	{
		updateCallbacks.push_back(std::make_tuple(0.f, 0.f, func));
	}

	template<class Self, class ...Components>
	void EntitySystem<Self, Components...>::BindForFixedUpdate(float interval, std::function<void(float)> func)
	{
		updateCallbacks.push_back(std::make_tuple(interval, 0.f, func));
	}


	template<class Self, class ...Components>
	template<class ComponentType, class ...ComponentTypes>
	inline void EntitySystem<Self, Components...>::GetComponentsInternal(std::unordered_map<std::type_index, uint32>& typeCount, ComponentType** component, ComponentTypes** ...components)
	{
		*component = componentManager->GetComponent<ComponentType>(currentEntityID, typeCount[typeid(ComponentType)]);
		typeCount[typeid(ComponentType)]++;

		GetComponentsInternal(typeCount, components...);
	}

	template<class Self, class ...Components>
	template<class ComponentType>
	inline void EntitySystem<Self, Components...>::GetComponentsInternal(std::unordered_map<std::type_index, uint32>& typeCount, ComponentType** component)
	{
		*component = componentManager->GetComponent<ComponentType>(currentEntityID, typeCount[typeid(ComponentType)]);
		typeCount[typeid(ComponentType)]++;
	}
#pragma endregion

}
