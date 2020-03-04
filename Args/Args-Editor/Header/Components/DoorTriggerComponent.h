#pragma once
#include <vector>
#include "Base Components/Transform.h"

struct PressureTriggerComponent;

namespace Args
{
	struct DoorTriggerComponent : public Component<DoorTriggerComponent>
	{
		std::vector<PressureTriggerComponent*> PressureToActive;
		Vector3 ClosedPosition;
		Vector3 OpenPosition;
		bool activated;

		DoorTriggerComponent(Entity* entity) : Component<DoorTriggerComponent>(entity)
		{
			
		}
		// Inherited via Component
		virtual std::string ObjectType() override
		{
			return std::string();
		}

		virtual bool SetData(const std::string& name, const std::string& value) override
		{
			return false;
		}

		virtual bool GetData(const std::string& name, std::string& value) override
		{
			return false;
		}
	};
}
