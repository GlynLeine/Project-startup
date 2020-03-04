#include "Module/MovementModule.h"
#include "Components/Movement1Component.h"
#include "Components/Movement2Component.h"
#include "Systems/Movement1System.h"
#include "Systems/Movement2System.h"


void Args::MovementModule::InitSystems(const std::set<std::string>& arguments)
{
	RegisterSystem<Movement1System>(60);
	RegisterSystem<Args::Movement2System>(60);
}

void Args::MovementModule::InitComponents(const std::set<std::string>& arguments)
{
	RegisterComponentType<Args::Movement2Component>();
	RegisterComponentType<Args::Movement1Component>();
}


