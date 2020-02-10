#include <Args-Core.h>
#include <Args-Physics.h>
#include "TestSystem.h"
#include "Networking\Client.h"
#pragma comment(lib, "Ws2_32.lib")

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
	ecs.RegisterSystem<SerialisationSystem>(0);

	ecs.RegisterComponentType<TestComponent>();

	uint32 entity = ecs.CreateEntity();
	ecs.AddComponent<TestComponent>(entity);
	ecs.AddComponent<TestComponent>(entity);
	Client client;
	client.start();
	/*ecs.InitialiseSystems();
	Debug::CloseOutputFile();
	ecs.UpdateSystems();
	ecs.UpdateSystems();
	ecs.UpdateSystems();
	ecs.UpdateSystems();
	ecs.UpdateSystems();*/

	// go ahead and do some physics stuff
	//PhysicsWorld physicsWorld;

	//Debug::CloseOutputFile();
	system("pause");
}
