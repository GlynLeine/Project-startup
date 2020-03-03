#include "Hierarchy/System/SceneSystem.h"

Args::SceneSystem::SceneSystem()
{

}

void Args::SceneSystem::Init()
{
	LoadScene("SampleScene");
}
unsigned Args::SceneSystem::LoadScene(std::string fileName)
{
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
	pbrMaterial->SetParam<float>("heightScale", 1.f);
	Args::Mesh::CreateMesh("TestMesh", "Cube.obj");

	Args::Material* testMaterial = Args::Material::CreateMaterial("testMaterial", Args::Shader::GetShader("ColorShader"));
	testMaterial->SetParam<Args::Vector4>("diffuseColor", Args::Vector4(0.f, 1.f, 0.f, 1.f));
	Debug::Log(DebugInfo,"Loading Scene");
	SceneComponent* sceneManager = GetGlobalComponent<SceneComponent>();
	std::string json = sceneManager->jsonLoader.LoadSceneFile(fileName);
	Document dom;
	dom.Parse(json.c_str());

	Debug::Log(DebugInfo, "Aserting...");
	assert(dom["Scene"].IsArray());
	Debug::Log(DebugInfo, "...Done!");

	const Value& Scene = dom["Scene"].GetArray();
	SizeType index = 0;
	while (index < Scene.Size())
	{
		const Value& object = Scene[index];
		Args::uint32 entity = componentManager->CreateEntity();
		if (object["name"].IsString())
		{
			Debug::Log(DebugInfo, "Name: %s", object["name"].GetString());
			//set name to proper object
		}
		if (object["components"].IsArray())
		{
			const Value& components = object["components"];
			Debug::Log(DebugInfo, "\t Components");
			//create components
			for (SizeType i = 0; i < components.Size(); i++)
			{
				Debug::Log(DebugInfo, "\t\t%s", components[i]["name"].GetString());
				std::string name = components[i]["name"].GetString();
				if (name._Equal("Transform"))
				{
					//Create Transform
					Args::Transform* transform;
					componentManager->AddComponent<Args::Transform>(entity, &transform);

					//Set Position
					assert(components[i]["position"].IsObject());
					Debug::Log(DebugInfo, "Components[%i] position isObject", i);
					//auto vec = components[i]["position"];
					assert(components[i]["position"]["x"].IsFloat());
					Debug::Log(DebugInfo, "vec x is float");
					transform->SetPosition(Args::Vec3(components[i]["position"]["x"].GetFloat(), components[i]["position"]["y"].GetFloat(), components[i]["position"]["z"].GetFloat()));

					//Set Rotation
					assert(components[i]["rotation"].IsObject());
					Debug::Log(DebugInfo, "Components[%i] rotation isObject", i);
					//auto rot = components[i]["rotation"].GetArray();
					assert(components[i]["rotation"]["x"].IsFloat());
					Debug::Log(DebugInfo, "rot x is float");
					transform->SetRotation(Args::Quaternion(components[i]["rotation"]["x"].GetFloat(), components[i]["rotation"]["y"].GetFloat(), components[i]["rotation"]["z"].GetFloat(), components[i]["rotation"]["w"].GetFloat()));

					//Set Scale
					assert(components[i]["scale"].IsObject());
					Debug::Log(DebugInfo, "Components[%i] scale isObject", i);
					//auto scale = components[i]["scale"].GetArray();
					assert(components[i]["scale"]["x"].IsFloat());
					Debug::Log(DebugInfo, "scale x is float");
					transform->SetScale(Args::Vec3(components[i]["scale"]["x"].GetFloat(), components[i]["scale"]["y"].GetFloat(), components[i]["scale"]["z"].GetFloat()));
				}
				else if (name._Equal("MeshFilter"))
				{
					//Create Mesh
					Args::Renderable* renderable;
					componentManager->AddComponent<Args::Renderable>(entity, &renderable);
					assert(components[i]["material"].IsString());
					Debug::Log(DebugInfo, "Components[%i] Mesh material is string", i);
					std::string matName = components[i]["material"].GetString();
					renderable->SetMaterial(*Args::Material::GetMaterial(matName));

					assert(components[i]["mesh"].IsString());
					Debug::Log(DebugInfo, "Components[%i] Mesh mesh is string", i);
					std::string meshName = components[i]["mesh"].GetString();
					Args::Mesh::CreateMesh("Mesh", meshName+".obj");
					renderable->SetMesh("Mesh");


				}
				else if (name._Equal("Rigidbody"))
				{
					//Create Rigibody
					//Args::Rigidbody* rigidbody;
					//componentManager->AddComponent<Args::Rigidbody>(entity, &rigidbody);
				}
				else if (name._Equal("SphereCollider"))
				{
					//Create SphereCollider
					/*Args::Collider* collider;
					componentManager->AddComponent<Args::Collider>(entity, &collider);*/
				}
				else if (name._Equal("BoxCollider"))
				{
					//Create BoxCollider
					/*Args::Collider* collider;
					componentManager->AddComponent<Args::Collider>(entity, &collider);*/
				}
				else if (name._Equal("Light"))
				{
					//Creat Light
					Args::Light* light;
					componentManager->AddComponent<Args::Light>(entity, &light);
					light->SetType(Args::LightType::POINT);
					//Get Light type
					//assert(components[i]["name"]["type"].IsInt());
					////Debug::Log(DebugInfo, "Components[%i] Light type is int", i);
					//int type = components[i]["name"]["type"].GetInt();
					//switch (type)
					//{
					//case 0:
					//	light->SetType(Args::LightType::DIRECTIONAL);
					//	break;
					//case 1:
					//	light->SetType(Args::LightType::POINT);
					//	break;
					//case 2:
					//	light->SetType(Args::LightType::SPOT);
					//	break;
					//}
				}
				else if (components[i]["name"].GetString() == "Camera")
				{
					//Create Camera
					Args::Camera* camera;
					componentManager->AddComponent<Args::Camera>(entity, &camera);
					camera->projection = Args::perspective(90.f, 1920.f / 1080.f, 0.001f, 1000.f);
				}
				else
				{
					//This will be used to create other known scripts
					Debug::Warning(DebugInfo, "Unsupported Script, Please contact your local developer at +31 0618829295");
				}
			}
		}
		Debug::Log(DebugInfo, "Done...");
		//add object to scene
		index++;
		sceneManager->sceneList.push_back(index);
	}

	return 0;
}

void Args::SceneSystem::UnloadScene(unsigned sceneID)
{
}

void Args::SceneSystem::AddObjectToScene(unsigned objectID, unsigned sceneID)
{
}

unsigned Args::SceneSystem::CurrentScene()
{
	return 0;
}


