#include <Args-Core.h>
#include <Args-Physics.h>
#include <Args-Rendering.h>
#include <Args-Math.h>
#include <Args-Window.h>
#include "Systems/TestSystem.h"

using namespace Args;

#include "Module/TestModule.h"
#include "Components/TestComponent.h"

#include "Networking/Client.h"
#include "Networking/Server.h"


int main(int argc, char* argv[])
{
	Debug::ResetColor(SUCCESS);

	Debug::Error(DebugInfo, "Example error");
	Debug::Success(DebugInfo, "Example success");
	Debug::Warning(DebugInfo, "Example warning");

	Args::Engine engine(argc, argv);

	//engine.RegisterSystem<>(50);
	engine.AttachModule<WindowModule>();
	engine.AttachModule<TestModule>();
	engine.AttachModule<RenderingModule>();

	engine.Initialise();

	for (int i = 0; i < 10000; i++)
	{
		uint32 entity = engine.CreateEntity();
		engine.AddComponent<TestComponentA>(entity);
		engine.AddComponent<TestComponentA>(entity);
	}

	uint32 renderEntity = engine.CreateEntity();
	engine.AddComponent<Args::Renderable>(renderEntity);
	engine.AddComponent<TestComponentA>(renderEntity);

	renderEntity = engine.CreateEntity();
	engine.AddComponent<Args::Renderable>(renderEntity);
	engine.AddComponent<TestComponentB>(renderEntity);

	engine.Run();

	// go ahead and do some physics stuff

	system("pause");
}
