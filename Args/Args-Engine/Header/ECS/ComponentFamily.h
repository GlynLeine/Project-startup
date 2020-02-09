#pragma once
#include "ECS/Component.h"
#include <vector>
#include <unordered_map>
#include <iostream>


namespace Args
{
	class IComponentFamily
	{
	public:
		virtual uint32 CreateComponent(uint32 entityID) = 0;
	};

	template<class ComponentType, INHERITS_FROM(ComponentType, Component<ComponentType>)>
	class TypedComponentFamily : public IComponentFamily
	{
		std::vector<ComponentType> components;
		uint32 componentTypeId;
	public:

		TypedComponentFamily(uint32 id) : componentTypeId(id)
		{
			ComponentType::id = id;
		}

		virtual uint32 CreateComponent(uint32 entityID) override
		{
			components.push_back(ComponentType(entityID));
			components[components.size() - 1].id = componentTypeId;
			Debug::Log(DebugInfo, "Created component %s for entity %i", GetTypeName<ComponentType>().c_str(), (int)entityID);
			return ret;
		}

		template<class ComponentType, INHERITS_FROM(ComponentType, Component<ComponentType>)>
		std::unordered_map<uint32, ComponentType*> GetComponents()
		{
			std::unordered_map<uint32, ComponentType*> ret;

			for (int i = 0; i < components.size(); i++)
			{
				ret[components[i].ownerID] = &components[i];
			}

			return ret;
		}
	};
}