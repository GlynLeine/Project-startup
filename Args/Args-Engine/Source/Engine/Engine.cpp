#include "Engine/Engine.h"
#include "Events/DefaultEvents.h"
#include "Utils/Common.h"

#ifdef ARGS_HIGH_PERFORMANCE
__declspec(dllexport) DWORD NvOptimusEnablement = 0x0000001;
__declspec(dllexport) int AmdPowerXpressRequestHighPerformance = 1;
#endif

std::set<Args::uint32> Args::Engine::events;
std::unordered_map<std::type_index, std::vector<std::function<void(Args::IEvent&)>>> Args::Engine::eventCallbacks;

Args::Engine::Engine(int argc, char* argv[])
{
	commandlineArguments = std::set<std::string>(argv, argv + (argc-1));
}

Args::Engine::Engine()
{
}

void Args::Engine::Initialise()
{
#ifdef ARGS_HIGH_PERFORMANCE
	SetPriorityClass(GetCurrentProcess(), REALTIME_PRIORITY_CLASS);
#endif

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

