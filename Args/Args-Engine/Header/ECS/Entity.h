#pragma once
#include <unordered_map>
#include <set>
#include <typeindex>
#include <type_traits>

#include <ECS/Component.h>

namespace Args
{
	class Entity
	{
	public:
		Entity(uint32 id) : ID(id) {};

		const uint32 ID;
		std::set<uint32> containedComponents;
		std::unordered_map<std::type_index, std::vector<IComponent*>> components;

		template<class ComponentType, class... Components>
		void GetComponents(ComponentType*& component, Components*&... components);

	private:
		std::unordered_map<std::type_index, int> componentRequestCount;

		void GetComponents() { componentRequestCount.clear(); };
	};


	template<class ComponentType, class ...Components>
	void Entity::GetComponents(ComponentType*& component, Components*& ...components)
	{
		static_assert(std::is_base_of_v<IComponent, ComponentType>, "One of the passed components doesn't inherit from Component.");

		if (componentRequestCount.size() == 0)
			componentRequestCount[typeid(ComponentType)] = 0;

		component = dynamic_cast<ComponentType*>(this->components[typeid(ComponentType)][componentRequestCount[typeid(ComponentType)]]);
		componentRequestCount[typeid(ComponentType)]++;
		std::printf("fetched component %s \n", typeid(ComponentType).name());

		GetComponents(components...);
	}
}