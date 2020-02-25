#include "WindowSystem.h"
#include "Window.h"
#include "WindowEvents.h"

void Args::WindowSystem::Init()
{
	Window* window = componentManager->GetGlobalComponent<Window>();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwSetErrorCallback(WindowSystem::OnError);

	if (!glfwInit())
		return;

	window->Create(1280, 720, "sahhh");
	Debug::Log(DebugInfo, "Window Created");

	int major = glfwGetWindowAttrib(window->handle, GLFW_CONTEXT_VERSION_MAJOR);
	int minor = glfwGetWindowAttrib(window->handle, GLFW_CONTEXT_VERSION_MINOR);
	int revision = glfwGetWindowAttrib(window->handle, GLFW_CONTEXT_REVISION);

	if (!window->handle)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window->handle);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window->handle, WindowSystem::OnInput);
	glfwSetWindowCloseCallback(window->handle, WindowSystem::OnClose);

	BindForUpdate(std::bind(&WindowSystem::Update, this, std::placeholders::_1));
	Engine::BindToEvent<Events::Exit>(std::bind(&WindowSystem::OnExit, this, std::placeholders::_1));

	Debug::Success(DebugInfo, "Initialised window with OpenGL version %i.%i%i", major, minor, revision);
	Debug::Log(DebugInfo, "Window Done");
}

void Args::WindowSystem::Update(float deltaTime)
{

	if (glfwJoystickPresent(0) == GLFW_FALSE)
	{
		glfwSetJoystickCallback(WindowSystem::OnControllerConnected);
		glfwSetJoystickCallback(WindowSystem::WhileControllerConnected);
	}
	if (glfwJoystickPresent(0) == GLFW_TRUE)
	{
		glfwSetJoystickCallback(WindowSystem::OnControllerDisconnected);
	}
	glfwPollEvents();
}

void Args::WindowSystem::OnExit(IEvent& event)
{
	Window* window = componentManager->GetGlobalComponent<Window>();
	glfwDestroyWindow(window->handle);
	window->handle = nullptr;
	Debug::Log(DebugInfo, "Closing");
}

void Args::WindowSystem::OnError(int error, const char* description)
{
	Debug::Error(DebugInfo, "Encountered glfw error %i: %s", error, description);
}

void Args::WindowSystem::OnInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	Engine::RaiseEvent<Events::KeyInput>(key, scancode, action, mods);
}

void Args::WindowSystem::OnClose(GLFWwindow* window)
{
	Engine::RaiseEvent<Events::WindowClose>();
	Engine::RaiseEvent<Events::Exit>();
}

void Args::WindowSystem::OnControllerConnected(int controllerID, int event)//Initial Connect
{
	Engine::RaiseEvent<Events::ControllerConnected>(controllerID, event);
}

void Args::WindowSystem::WhileControllerConnected(int controllerID, int event)//While Connecting
{
	Engine::RaiseEvent<Events::ControllerConnect>(controllerID, event);
}

void Args::WindowSystem::OnControllerDisconnected(int controllerID, int event)//Disconnect
{
	Engine::RaiseEvent<Events::ControllerDisconnected>(controllerID, event);
}
