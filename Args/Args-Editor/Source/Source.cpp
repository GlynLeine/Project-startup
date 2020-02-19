#include <Args-Core.h>
#include <Args-Physics.h>
#include <Args-Rendering.h>
#include <Args-Math.h>
#include <Args-Window.h>

using namespace Args;

#include "Module\TestModule.h"
#include "Components\TestComponent.h"

#include "Networking\Client.h"
#include "Networking\Server.h"


int main(int argc, char* argv[])
{
	Debug::ResetColor(SUCCESS);

	Debug::Error(DebugInfo, "Some error");
	Debug::Success(DebugInfo, "Some success");
	Debug::Warning(DebugInfo, "Some warning");

	Args::Engine engine(argc, argv);

	//engine.RegisterSystem<JSONLoader>(50);
	engine.AttachModule<WindowModule>();
	engine.AttachModule<TestModule>();
	engine.AttachModule<RenderingModule>();

	engine.Initialise();

	uint32 entity = engine.CreateEntity();
	engine.AddComponent<TestComponent>(entity);
	engine.AddComponent<TestComponent>(entity);

	engine.Run();

	// go ahead and do some physics stuff
	PhysicsWorld physicsWorld;

	system("pause");
}
