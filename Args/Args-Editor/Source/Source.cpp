#include <Args-Core.h>
#include <Args-Physics.h>
#include <Args-Rendering.h>
#include <Args-Math.h>
#include <Args-Window.h>
#include "Systems/TestSystem.h"

#include <Module/TestModule.h>
#include <Components/TestComponent.h>

#include <Networking/Client.h>
#include <Networking/Server.h>

#include <Input/InputSystem.h>
#include <Module/InputModule.h>


int main(int argc, char* argv[])
{
	Args::Debug::ResetColor(SUCCESS);

	try
	{
		Args::Debug::Error(DebugInfo, "Example error");
	}
	catch (std::logic_error e)
	{
		Args::Debug::Log(DebugInfo, "Caught error: %s", e.what());
	}

	Args::Debug::Success(DebugInfo, "Example success");
	Args::Debug::Warning(DebugInfo, "Example warning");

	Args::Engine engine(argc, argv);


	//engine.RegisterSystem<InputSystem>(50);
	engine.AttachModule<Args::WindowModule>();
	engine.AttachModule<TestModule>();
	engine.AttachModule<Args::RenderingModule>();
	engine.AttachModule<Args::InputModule>();

	engine.Initialise();

	for (int i = 0; i < 10000; i++)
	{
		Args::uint32 entity = engine.CreateEntity();
		engine.AddComponent<TestComponentA>(entity);
		engine.AddComponent<TestComponentA>(entity);
	}

	Args::Texture::CreateTexture("Default", "missing-texture.png");
	Args::Shader::CreateShader("PBRShader", "color.vert", "color.frag");
	Args::Material* pbrMaterial = Args::Material::CreateMaterial("PBRMat", Args::Shader::GetShader("PBRShader"));
	pbrMaterial->SetParam<Args::Vector4>("diffuseColor", Args::Vector4(1.f));
	Args::Mesh::CreateMesh("TestMesh", "UVSphereSmooth.obj");

	Args::uint32 cameraEntity = engine.CreateEntity();

	Args::Camera* camera;
	engine.AddComponent<Args::Camera>(cameraEntity, &camera);
	camera->projection = Args::perspective(90.f, 1920.f / 1080.f, 0.001f, 1000.f);

	Args::Transform* transform;
	engine.AddComponent<Args::Transform>(cameraEntity, &transform);
	transform->matrix = Args::inverse(Args::lookAt(Args::zero, Args::forward, Args::up));

	Args::uint32 renderEntity = engine.CreateEntity();

	Args::Renderable* renderable;
	engine.AddComponent<Args::Renderable>(renderEntity, &renderable);
	renderable->SetMaterial("PBRMat");
	renderable->SetMesh("TestMesh");

	engine.AddComponent<Args::Transform>(renderEntity, &transform);
	transform->position.z = -1;

	renderEntity = engine.CreateEntity();
	engine.AddComponent<Args::Renderable>(renderEntity, &renderable);
	renderable->SetMaterial("PBRMat");
	renderable->SetMesh("TestMesh");
	engine.AddComponent<Args::Transform>(renderEntity);

	engine.Run();

	// go ahead and do some physics stuff

	system("pause");
}
