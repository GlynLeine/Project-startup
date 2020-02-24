#include <Args-Core.h>
#include <Args-Physics.h>
#include <Args-Math.h>
#include <Args-Window.h>

using namespace Args;

#include "Systems\TestSystem.h"
#include "Systems\TestMonoUpdateSystem.h"
#include "Components\TestGlobalComponent.h"



int main(int argc, char* argv[])
{
	Debug::ResetColor(SUCCESS);

	Debug::Error(DebugInfo, "Some error");
	Debug::Success(DebugInfo, "Some success");
	Debug::Warning(DebugInfo, "Some warning");

	Args::Engine engine(argc, argv);

	engine.RegisterComponentType<TestComponent>();
	engine.RegisterStaticComponentType<TestGlobalComponent>();
	engine.RegisterStaticComponentType<Window>();

	engine.RegisterSystem<TestSystem>();
	engine.RegisterSystem<TestMonoUpdateSystem>();
	//engine.RegisterSystem<JSONLoader>(50);
	engine.RegisterSystem<WindowSystem>(0);


	uint32 entity = engine.CreateEntity();
	engine.AddComponent<TestComponent>(entity);
	engine.AddComponent<TestComponent>(entity);

	engine.Initialise();
	engine.Run();

	// go ahead and do some physics stuff

	system("pause");
}
