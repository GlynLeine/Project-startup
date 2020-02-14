#include "WindowSystem.h"
#include "Window.h"

void Args::WindowSystem::Init()
{
	Window* window = componentManager->GetGlobalComponent<Window>();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);		 // yes, 3 and 2!!!
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 4);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // But also 4 if present
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	glfwSetErrorCallback(WindowSystem::OnError);

	if (!glfwInit())
		return;

	window->Create(1280, 720, "sahhh");

	int major = glfwGetWindowAttrib(window->handle, GLFW_CONTEXT_VERSION_MAJOR);
	int minor = glfwGetWindowAttrib(window->handle, GLFW_CONTEXT_VERSION_MINOR);
	int revision = glfwGetWindowAttrib(window->handle, GLFW_CONTEXT_REVISION);
	std::cout << "OpenGL Version " << major << "." << minor << "." << revision << std::endl;

	if (!window->handle)
	{
		glfwTerminate();
		return;
	}

	glfwMakeContextCurrent(window->handle);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window->handle, WindowSystem::OnInput);
	glfwSetWindowCloseCallback(window->handle, WindowSystem::OnClose);
	glfwSetJoystickCallback(WindowSystem::OnControllerConnected);

	BindForUpdate(std::bind(&WindowSystem::Update, this, std::placeholders::_1));
}

void Args::WindowSystem::Update(float deltaTime)
{
	glfwPollEvents();
	if (Engine::CheckEvent<Events::Exit>())
		glfwDestroyWindow(componentManager->GetGlobalComponent<Window>()->handle);
}

void Args::WindowSystem::OnError(int error, const char* description)
{
	Debug::Error(DebugInfo, "Encountered glfw error %i: %s", error, description);
}

void Args::WindowSystem::OnInput(GLFWwindow* window, int key, int scancode, int action, int mods)
{
}

void Args::WindowSystem::OnClose(GLFWwindow* window)
{
	Engine::RaiseEvent<Events::Exit>();
}

void Args::WindowSystem::OnControllerConnected(int controllerID, int event)
{
}
