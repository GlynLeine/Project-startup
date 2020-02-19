#include "Module\RenderingModule.h"
#include "Components\Renderable.h"
#include "Renderer\Renderer.h"

void Args::RenderingModule::InitComponents(const std::set<std::string>& arguments)
{
	RegisterComponentType<Renderable>();
}

void Args::RenderingModule::InitSystems(const std::set<std::string>& arguments)
{
	if (!arguments.count("norender") && !arguments.count("nowindow"))
		RegisterSystem<Renderer>(1);
}
