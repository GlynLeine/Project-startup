#include "Module/RenderingModule.h"
#include "Components/Renderable.h"
#include "Components/Camera.h"
#include "Components/Light.h"
#include "Renderer/Renderer.h"

void Args::RenderingModule::InitComponents(const std::set<std::string>& arguments)
{
	RegisterComponentType<Renderable>();
	RegisterComponentType<Camera>();
	RegisterComponentType<Light>();
}

void Args::RenderingModule::InitSystems(const std::set<std::string>& arguments)
{
	if (!arguments.count("norender") && !arguments.count("nowindow"))
		RegisterSystem<Renderer>(1);
}
