#pragma once
#include <vector>

struct DoorTriggerComponent;

namespace Args
{
	struct ButtonTriggerComponent
	{
		std::vector<DoorTriggerComponent*> DoorsToOpen;
		std::vector<DoorTriggerComponent*> DoorsToClose;
	};
}
