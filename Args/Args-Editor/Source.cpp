#include <Args.h>

#include "TestSystem.h"



int main()
{
	ECS ecs;

	std::printf((std::string("../Logs/output") + Debug::GetDateTime() + std::string(".log")).c_str());

	for (int i = 0; i < 255; i++)
	{
		Debug::Log(i, DebugInfo, "color mode: %i", i);
	}

	std::printf("\n\n\n");

	Debug::ResetColor(SUCCESS);

	Debug::Error(DebugInfo, "Some error");
	Debug::Success(DebugInfo, "Some success");
	Debug::Warning(DebugInfo, "Some warning");

	ecs.RegisterSystem<TestSystem>();
	ecs.RegisterComponentType<TestComponent>();

	uint32 entity = ecs.CreateEntity();
	ecs.AddComponent<TestComponent>(entity);
	ecs.AddComponent<TestComponent>(entity);
	ecs.InitialiseSystems();
	Debug::CloseOutputFile();
	ecs.UpdateSystems();
	ecs.UpdateSystems();
	ecs.UpdateSystems();
	ecs.UpdateSystems();
	ecs.UpdateSystems();

	Debug::CloseOutputFile();
	system("pause");
}
