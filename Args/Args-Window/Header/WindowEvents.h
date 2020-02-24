#pragma once
#include <Args-Core.h>

namespace Args
{
	namespace Events
	{
		struct WindowClose : public Event<WindowClose> {};

		struct KeyInput : public Event<KeyInput>
		{
			int key; int scancode; int action; int mods;
			KeyInput(int key, int scancode, int action, int mods) : key(key), scancode(scancode), action(action), mods(mods) {}
		};

		struct ControllerConnect : public Event<ControllerConnect>
		{
			int controllerID; int event;
			ControllerConnect(int controllerID, int event) : controllerID(controllerID), event(event) {}
		};
	}
}