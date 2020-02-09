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
		ComponentManager* componentManager;

		std::vector<std::tuple<float, float, std::function<void(float)>>> updateCallbacks;

	public:
		virtual void Init() = 0;
		virtual void UpdateEntities(float deltaTime) = 0;
		virtual std::set<uint32> GetComponentRequirements() = 0;
		bool Enable(bool enabled) { this->enabled = enabled; }
	};

	template<class Self, class... Components>
	class System : public ISystem
	{
	private:
		static std::set<uint32> componentRequirements;

		std::tuple<std::unordered_map<uint32, Components *...>>* components;
	public:
		virtual std::set<uint32> GetComponentRequirements() override;

	protected:

		void GetComponents(Components*&... components);

		void BindForUpdate(UpdateFunc<Self> func);
		void BindForFixedUpdate(float interval, UpdateFunc<Self> func);

		uint32 currentEntityID = 1;

		System(Self* self);

		virtual void UpdateEntities(float deltaTime) override;
	};

	template<class Self, class... Components>
	std::set<uint32> System<Self, Components...>::componentRequirements;

	template<class Self, class... Components>
	System<Self, Components...>::System(Self* self)
	{
		static_assert((std::is_base_of_v<IComponent, Components> || ...), "One of the passed components doesn't inherit from Component.");
	}

	template<class Self, class ...Components>
	void System<Self, Components...>::UpdateEntities(float deltaTime)
	{
		auto components = componentManager->GetComponents<Components...>();
		this->components = &components;
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
	void System<Self, Components...>::GetComponents(Components*&... components)
	{
		std::array<IComponent*&, sizeof...(components)> ptrArray = { components... };
		for (int i = 0; i < sizeof...(components); i++)
			ptrArray[i] = (std::get<i>(this->components)[currentEntityID]);

	}

	template<class Self, class ...Components>
	void System<Self, Components...>::BindForUpdate(UpdateFunc<Self> func)
	{
		updateCallbacks.push_back(std::make_tuple(0.f, 0.f, std::bind(func, this, std::placeholders::_1)));
	}

	template<class Self, class ...Components>
	void System<Self, Components...>::BindForFixedUpdate(float interval, UpdateFunc<Self> func)
	{
		updateCallbacks.push_back(std::make_tuple(interval, 0.f, std::bind(func, this, std::placeholders::_1)));
	}
}
