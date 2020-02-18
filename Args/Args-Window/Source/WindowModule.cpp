#include "WindowModule.h"
#include "Window.h"
#include "WindowSystem.h"

void Args::WindowModule::InitComponents(const std::set<std::string>& arguments)
{
	RegisterGlobalComponentType<Window>();
}

void Args::WindowModule::InitSystems(const std::set<std::string>& arguments)
{
	RegisterSystem<WindowSystem>(0);
}
