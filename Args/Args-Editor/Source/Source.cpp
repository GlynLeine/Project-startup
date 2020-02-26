#include <Args-Core.h>
#include <Args-Physics.h>
#include <Args-Rendering.h>
#include <Args-Math.h>
#include <Args-Window.h>


using namespace Args;

#include <Module/TestModule.h>
#include <Components/TestComponent.h>

#include <Networking/Client.h>
#include <Networking/Server.h>

#include <Input/InputSystem.h>
#include <Module/InputModule.h>


int main(int argc, char* argv[])
{
	Debug::ResetColor(SUCCESS);

	try
	{
		Debug::Error(DebugInfo, "Example error");
	}
	catch (std::logic_error e)
	{
		Debug::Log(DebugInfo, "Caught error: %s", e.what());
	}

	Debug::Success(DebugInfo, "Example success");
	Debug::Warning(DebugInfo, "Example warning");

	Args::Engine engine(argc, argv);


	//engine.RegisterSystem<InputSystem>(50);
	engine.AttachModule<WindowModule>();
	engine.AttachModule<TestModule>();
	//engine.AttachModule<RenderingModule>();
	//engine.AttachModule<InputModule>();

	engine.Initialise();

	for (int i = 0; i < 10000; i++)
	{
		uint32 entity = engine.CreateEntity();
		engine.AddComponent<TestComponentA>(entity);
		engine.AddComponent<TestComponentA>(entity);
	}

	//Args::Shader::CreateShader("PBRShader", "PBR.vert", "PBR.frag");
	//Args::Material::CreateMaterial("PBRMat", Args::Shader::GetShader("PBRShader"));
	//Args::Mesh::CreateMesh("TestMesh", "UVSphereSmooth.obj");

	//uint32 cameraEntity = engine.CreateEntity();

	//engine.AddComponent<Args::Camera>(cameraEntity);
	//engine.AddComponent<Args::Transform>(cameraEntity);

	//uint32 renderEntity = engine.CreateEntity();

	//Renderable* renderable;
	//engine.AddComponent<Args::Renderable>(renderEntity, &renderable);
	//renderable->SetMaterial("PBRMat");
	//renderable->SetMesh("TestMesh");

	////engine.GetComponent
	//engine.AddComponent<Args::Transform>(renderEntity);

	//renderEntity = engine.CreateEntity();
	//engine.AddComponent<Args::Renderable>(renderEntity, &renderable);
	//renderable->SetMaterial("PBRMat");
	//renderable->SetMesh("TestMesh");
	//engine.AddComponent<Args::Transform>(renderEntity);

	engine.Run();

	// go ahead and do some physics stuff

	system("pause");
}
