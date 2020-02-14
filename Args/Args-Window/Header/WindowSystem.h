#pragma once
#include <Args-Core.h>

struct GLFWwindow;

namespace Args
{
	class WindowSystem : public GlobalSystem<WindowSystem>
	{
	public:
		WindowSystem() : GlobalSystem<WindowSystem>() {}

		// Inherited via GlobalSystem
		virtual void Init() override;

		static void OnError(int error, const char* description);
		static void OnInput(GLFWwindow* window, int key, int scancode, int action, int mods);
		static void OnClose(GLFWwindow* window);
		static void OnControllerConnected(int controllerID, int event);
	};
}