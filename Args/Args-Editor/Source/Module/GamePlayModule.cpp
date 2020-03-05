#include "Module/GamePlayModule.h"
#include "Components/Movement1Component.h"
#include "Components/Movement2Component.h"
#include "Systems/Movement1System.h"
#include "Systems/Movement2System.h"
#include "Systems/DoorSystem.h"


void Args::GamePlayModule::InitSystems(const std::set<std::string>& arguments)
{
	RegisterSystem<Args::Movement1System>(50);
	RegisterSystem<Args::Movement2System>(50);
	RegisterSystem<Args::DoorSystem>(50);
}

void Args::GamePlayModule::InitComponents(const std::set<std::string>& arguments)
{
	RegisterComponentType<Args::Movement1Component>();
	RegisterComponentType<Args::Movement2Component>();
	RegisterComponentType<Args::PickupComponent>();
	RegisterComponentType<Args::DoorTriggerComponent>();
}


