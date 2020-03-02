#include <Args-Core.h>
#include <Args-Physics.h>
#include <Args-Rendering.h>
#include <Args-Math.h>
#include <Args-Window.h>
#include <Args-Input.h>

#include "Systems/TestSystem.h"

#include "Module/TestModule.h"
#include "Components/TestComponent.h"

#include <Networking/Client.h>
#include <Networking/Server.h>



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

	engine.Initialise();

	Args::Texture::CreateTexture("Default", "Default/default-albedo.png");

	Args::Texture::CreateTexture("DefaultAlbedo", "Default/default-albedo.png");
	Args::Texture::CreateTexture("DefaultAo", "Default/default-ao.png");
	Args::Texture::CreateTexture("DefaultHeight", "Default/default-height.png");
	Args::Texture::CreateTexture("DefaultMetal", "Default/default-metal.png");
	Args::Texture::CreateTexture("DefaultNormal", "Default/default-normal.png");
	Args::Texture::CreateTexture("DefaultRoughness", "Default/default-roughness.png");



	Args::Shader::CreateShader("PBRShader", "PBR.vert", "PBR.frag");
	Args::Shader::CreateShader("ColorShader", "color.vert", "color.frag");
	Args::Material* pbrMaterial = Args::Material::CreateMaterial("PBRMat", Args::Shader::GetShader("PBRShader"));
	pbrMaterial->SetTexture("albedoMap", Args::Texture::GetTexture("DefaultAlbedo"));
	pbrMaterial->SetTexture("aoMap", Args::Texture::GetTexture("DefaultAo"));
	pbrMaterial->SetTexture("heightMap", Args::Texture::GetTexture("DefaultHeight"));
	pbrMaterial->SetTexture("metalMap", Args::Texture::GetTexture("DefaultMetal"));
	pbrMaterial->SetTexture("normalMap", Args::Texture::GetTexture("DefaultNormal"));
	pbrMaterial->SetTexture("roughnessMap", Args::Texture::GetTexture("DefaultRoughness"));

	Args::Mesh::CreateMesh("TestMesh", "UVSphereSmooth.obj");

	Args::Material * testMaterial = Args::Material::CreateMaterial("testMaterial", Args::Shader::GetShader("ColorShader"));
	testMaterial->SetParam<Args::Vector4>("diffuseColor", Args::Vector4(0.f, 1.f, 0.f, 1.f));

	for (int i = 0; i < 100; i++)
	{
		Args::uint32 entity = engine.CreateEntity();
		engine.AddComponent<TestComponentA>(entity);
		engine.AddComponent<TestComponentA>(entity);

		Args::Renderable* renderable;
		engine.AddComponent<Args::Renderable>(entity, &renderable);
		renderable->SetMaterial("testMaterial");
		renderable->SetMesh("TestMesh");

		Args::Transform* transform;
		engine.AddComponent<Args::Transform>(entity, &transform);
		transform->position.z = 3;
	}

	Args::uint32 cameraEntity = engine.CreateEntity();

	Args::Renderable* renderable;
	engine.AddComponent<Args::Renderable>(cameraEntity, &renderable);
	renderable->SetMaterial("PBRMat");
	renderable->SetMesh("TestMesh");

	Args::Camera* camera;
	engine.AddComponent<Args::Camera>(cameraEntity, &camera);
	float ratio = 1920.f / 1080.f;
	camera->projection = Args::perspective(90 / ratio, ratio, 0.001f, 1000.f);
	Args::Light* light;
	engine.AddComponent<Args::Light>(cameraEntity, &light);
	light->SetType(Args::LightType::POINT);
	light->SetColour(Args::Vector3(1.0));

	Args::Transform* transform;
	engine.AddComponent<Args::Transform>(cameraEntity, &transform);
	transform->matrix = Args::inverse(Args::lookAt(Args::zero, Args::forward, Args::up));

	Args::uint32 renderEntity = engine.CreateEntity();

	engine.AddComponent<Args::Renderable>(renderEntity, &renderable);
	renderable->SetMaterial("PBRMat");
	renderable->SetMesh("TestMesh");

	engine.AddComponent<Args::Transform>(renderEntity, &transform);
	transform->position.z = 5;
	transform->SetScale(Args::Vector3(2.5f));

	renderEntity = engine.CreateEntity();
	engine.AddComponent<Args::Renderable>(renderEntity, &renderable);
	renderable->SetMaterial("PBRMat");
	renderable->SetMesh("TestMesh");
	engine.AddComponent<Args::Transform>(renderEntity, &transform);
	transform->SetScale(Args::Vector3(2.5f));

	engine.Run();

	// go ahead and do some physics stuff

	system("pause");
}
