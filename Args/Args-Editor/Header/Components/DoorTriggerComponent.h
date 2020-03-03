#pragma once
#include <vector>
#include "Base Components/Transform.h"

struct PressureTriggerComponent;

namespace Args
{
	struct DoorTriggerComponent
	{
		std::vector<PressureTriggerComponent*> PressureToActive;
		Vector3 ClosedPosition;
		Vector3 OpenPosition;
		bool activated;

		DoorTriggerComponent()
		{
			
		}
	};
}
