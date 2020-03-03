#pragma once
#include <vector>

struct DoorTriggerComponent;

namespace Args
{
	struct PressureTriggerComponent
	{
		bool BeingPressed;
		std::vector<DoorTriggerComponent*> DoorsToOpen;
		std::vector<DoorTriggerComponent*> DoorsToClose;
		
		PressureTriggerComponent()
		{
			
		}
	};
}
