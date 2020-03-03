#include <Args-Core.h>
#include <Args-Physics.h>
#include <Args-Rendering.h>
#include <Args-Math.h>
#include <Args-Window.h>
#include <Args-Input.h>
#include <Args-Audio.h>

#include <Systems/TestSystem.h>

#include <Module/TestModule.h>
#include <Components/TestComponent.h>

#include <Networking/Client.h>
#include <Networking/Server.h>

#include <Hierarchy/System/SceneSystem.h>
#include <Hierarchy/Module/SceneModule.h>



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

	engine.AttachModule<Args::WindowModule>();
	engine.AttachModule<TestModule>();
	engine.AttachModule<Args::RenderingModule>();
	engine.AttachModule<Args::InputModule>();
	engine.AttachModule<Args::AudioModule>();
	engine.AttachModule<Args::SceneModule>();
	
	engine.Initialise();

	for (int i = 0; i < 100; i++)
	{
		Args::uint32 entity = engine.CreateEntity();
		engine.AddComponent<TestComponentA>(entity);
		engine.AddComponent<TestComponentA>(entity);

		Args::Renderable* renderable;
		engine.AddComponent<Args::Renderable>(entity, &renderable);
		renderable->SetMaterial("PBRMat");
		renderable->SetMesh("TestMeshSphere");

		Args::Transform* transform;
		engine.AddComponent<Args::Transform>(entity, &transform);
		transform->SetScale(Args::Vector3(0.1f));
		transform->position = Args::Vector3(((std::rand() % 200) / 10.f) - 10.f, ((std::rand() % 200) / 10.f) - 10.f, ((std::rand() % 200) / 10.f) - 10.f);
	}


	Args::uint32 cameraEntity = engine.CreateEntity();

	Args::Renderable* renderable;
	engine.AddComponent<Args::Renderable>(cameraEntity, &renderable);
	renderable->SetMaterial("PBRMat");
	renderable->SetMesh("TestMeshSphere");

	Args::Camera* camera;
	engine.AddComponent<Args::Camera>(cameraEntity, &camera);
	float ratio = 1920.f / 1080.f;
	camera->projection = Args::perspectiveLH(90 / ratio, ratio, 0.001f, 1000.f);

	engine.AddComponent<Args::AudioListener>(cameraEntity);

	Args::Transform* transform;
	engine.AddComponent<Args::Transform>(cameraEntity, &transform);
	transform->matrix = Args::inverse(Args::lookAtLH(Args::zero, Args::forward, Args::up));

	Args::Light* light;
	Args::uint32 directionalLight = engine.CreateEntity();
	engine.AddComponent<Args::Light>(directionalLight, &light);
	light->SetType(Args::LightType::DIRECTIONAL);
	light->SetColour(Args::Vector3(1.0));

	engine.AddComponent<Args::Transform>(directionalLight, &transform);
	transform->matrix = Args::lookAtLH(Args::zero, Args::Vector3(0, 1, -1), Args::up);

	Args::uint32 lightEntity = engine.CreateEntity();
	engine.AddComponent<Args::Light>(lightEntity, &light);
	light->SetType(Args::LightType::POINT);
	light->SetColour(Args::Vector3(1.0));

	Args::AudioSource* audioSource;
	engine.AddComponent<Args::AudioSource>(lightEntity, &audioSource);
	audioSource->Load("Moanin.mp3", true);
	audioSource->Play();

	engine.AddComponent<Args::Renderable>(lightEntity, &renderable);
	renderable->SetMaterial("testMaterial");
	renderable->SetMesh("TestMeshSphere");

	engine.AddComponent<Args::Transform>(lightEntity, &transform);
	transform->position = Args::Vector3(15, 5, 0);
	transform->SetScale(Args::Vector3(0.2f));

	Args::uint32 jazzEntity = engine.CreateEntity();
	engine.AddComponent<Args::AudioSource>(jazzEntity, &audioSource);
	audioSource->Load("Dave Brubeck - Take Five.mp3", true);
	audioSource->Play();

	engine.AddComponent<Args::Renderable>(jazzEntity, &renderable);
	renderable->SetMaterial("testMaterial");
	renderable->SetMesh("TestMeshSphere");

	engine.AddComponent<Args::Transform>(jazzEntity, &transform);
	transform->position = Args::Vector3(-15, 5, 0);
	transform->SetScale(Args::Vector3(0.2f));

	Args::uint32 renderEntity = engine.CreateEntity();

	engine.AddComponent<Args::Renderable>(renderEntity, &renderable);
	renderable->SetMaterial("GigbitMat");
	renderable->SetMesh("Gigbit");

	engine.AddComponent<Args::Transform>(renderEntity, &transform);
	transform->position.z = 15;
	transform->SetScale(Args::Vector3(2.5f));

	renderEntity = engine.CreateEntity();
	engine.AddComponent<Args::Renderable>(renderEntity, &renderable);
	renderable->SetMaterial("PBRMat");
	renderable->SetMesh("TestMeshSphere");
	engine.AddComponent<Args::Transform>(renderEntity, &transform);
	transform->SetScale(Args::Vector3(2.5f));

	engine.Run();

	// go ahead and do some physics stuff

	system("pause");
}
