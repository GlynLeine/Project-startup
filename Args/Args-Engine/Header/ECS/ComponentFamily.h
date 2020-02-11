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
		virtual IComponent* GetComponent(uint32 componentID) = 0;
		virtual uint32 GetComponentTypeID(uint32 componentID) = 0;
		virtual std::unordered_map<uint32, std::vector<IComponent*>> GetComponents() = 0;
	};

	template<class ComponentType, INHERITS_FROM(ComponentType, Component<ComponentType>)>
	class TypedComponentFamily : public IComponentFamily
	{
		std::vector<ComponentType> components;
		uint32 componentTypeId;
	public:

		TypedComponentFamily(uint32 id) : componentTypeId(id)
		{
		}

		virtual uint32 CreateComponent(uint32 entityID) override
		{
			uint32 id = (uint32)components.size() + 1;
			components.push_back(ComponentType(entityID));
			components[id-1].id = id;
			Debug::Log(DebugInfo, "Created component %s with id %u for entity %u", GetTypeName<ComponentType>().c_str(), id, entityID);
			return id;
		}

		virtual IComponent* GetComponent(uint32 componentID) override
		{
			return &(components[componentID-1]);
		}


		virtual std::unordered_map<uint32, std::vector<IComponent*>> GetComponents() override
		{
			std::unordered_map<uint32, std::vector<IComponent*>> ret;

			for (int i = 0; i < components.size(); i++)
			{
				ret[components[i].ownerID].push_back(&(components[i]));
			}

			return ret;
		}

		virtual uint32 GetComponentTypeID(uint32 componentID) override
		{
			return componentTypeId;
		}
	};
}