#pragma once
#include "ECS/Component.h"
#include <vector>
#include <memory>
#include <iostream>


namespace Args
{
	class IComponentFamily
	{
	public:
		virtual IComponent* CreateComponent(uint32 entityID) = 0;
	};

	template<class ComponentType, INHERITS_FROM(ComponentType, IComponent)>
	class TypedComponentFamily : public IComponentFamily
	{
		std::vector<ComponentType> components;
		uint32 componentTypeId;
	public:

		TypedComponentFamily(uint32 id) : componentTypeId(id) {}

		virtual IComponent* CreateComponent(uint32 entityID) override
		{
			components.push_back(ComponentType(entityID));
			components[components.size() - 1].id = componentTypeId;
			IComponent* ret = &components[components.size() - 1];
			ret->adress = (int)ret;
			Debug::Log(DebugInfo, "Created component %s for entity %i", GetTypeName<ComponentType>().c_str(), (int)entityID);
			return ret;
		}
	};
}