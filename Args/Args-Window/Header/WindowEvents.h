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



		struct ControllerConnected : public Event<ControllerConnected>//Initial Connect
		{
			int controllerID; int event;
			ControllerConnected(int controllerID, int event) : controllerID(controllerID), event(event) {}
		};

		struct ControllerIsConnected : public Event<ControllerIsConnected>//While its Connected
		{
			int controllerID; int event;
			ControllerIsConnected(int controllerID, int event) : controllerID(controllerID), event(event) {}
		};

		struct ControllerDisconnected : public Event<ControllerDisconnected>//Disconnect
		{
			int controllerID; int event;
			ControllerDisconnected(int controllerID, int event) : controllerID(controllerID), event(event) {}
		};
	}
}