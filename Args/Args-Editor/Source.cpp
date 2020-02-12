#include <Args-Core.h>
#include <Args-Physics.h>
#include <Args-Math.h>

#include "TestSystem.h"
#include "TestMonoUpdateSystem.h"
#include "TestGlobalComponent.h"

#include "Networking\Client.h"
#include "Networking\Server.h"
#pragma comment(lib, "Ws2_32.lib")

int main()
{
	ECS ecs;

	std::printf((std::string("../Logs/output") + Debug::GetDateTime() + std::string(".log")).c_str());

	for (int i = 0; i < 255; i++)
	{
		Debug::Log(i, DebugInfo, "color mode: %i", i);
	}

	Vector3 someVec;

	std::printf("\n\n\n");

	Debug::ResetColor(SUCCESS);

	Debug::Error(DebugInfo, "Some error");
	Debug::Success(DebugInfo, "Some success");
	Debug::Warning(DebugInfo, "Some warning");

	ecs.RegisterComponentType<TestComponent>();
	ecs.RegisterStaticComponentType<TestGlobalComponent>();

	ecs.RegisterSystem<TestSystem>();
	ecs.RegisterSystem<TestMonoUpdateSystem>();
	ecs.RegisterSystem<JSONLoader>(0);

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

	// go ahead and do some physics stuff
	PhysicsWorld physicsWorld;

	Debug::CloseOutputFile();
	system("pause");
}
