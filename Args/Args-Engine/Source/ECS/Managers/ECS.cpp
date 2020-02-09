#include "ECS/Managers/ECS.h"

uint32 Args::ECS::CreateEntity()
{
	return componentManager.CreateEntity();
}

void Args::ECS::InitialiseSystems()
{
	systemManager.InitialiseSystems();
}

void Args::ECS::UpdateSystems()
{
	systemManager.UpdateSystems();
}
