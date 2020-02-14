#include "Engine/Engine.h"
#include "Events/DefaultEvents.h"

std::set<uint32> Args::Engine::events;

Args::Engine::Engine(int argc, char* argv[])
{
	commandlineArguments = std::set<std::string>(argv, argv + (argc-1));
}

Args::Engine::Engine()
{
}

void Args::Engine::Initialise()
{
	for (auto& module : modules)
		module->InitComponents(commandlineArguments);

	for (auto& module : modules)
		module->InitSystems(commandlineArguments);

	ecs.InitialiseSystems();
}

void Args::Engine::Run()
{
	while (!CheckEvent<Events::Exit>())
	{
		ecs.UpdateSystems();
	}
}

Args::Engine::~Engine()
{
	Debug::CloseOutputFile();
}

