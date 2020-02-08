#include <Args-Core.h>
#include <Args-Physics.h>

#include "TestSystem.h"


int main()
{
	ECSManager manager;

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

	manager.RegisterSystem<TestSystem>();
	manager.RegisterComponentType<TestComponent>();

	uint32 entity = manager.CreateEntity();
	manager.AddComponent<TestComponent>(entity);
	manager.AddComponent<TestComponent>(entity);
	manager.InitialiseSystems();
	
	// go ahead and do some physics stuff
	PhysicsWorld physicsWorld;

	Debug::CloseOutputFile();
	system("pause");
}
