#pragma once
#include "Utils/Common.h"

namespace Args
{
	struct IEvent
	{
	protected:
		static uint32 eventCount;
	};

	template<typename Self>
	struct Event : public IEvent
	{
		static uint32 id;
	};

	template<typename Self>
	uint32 Event<Self>::id = eventCount++;
}