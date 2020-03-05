#include "Hierarchy/System/SceneSystem.h"
#include <Hierarchy/Component/SceneComponent.h>
#include <Args-Core.h>
#include <Args-Physics.h>
#include <Args-Rendering.h>
#include <Args-Math.h>
#include <Args-Window.h>
#include <Args-Input.h>
#include <Components/Rigidbody.h>
#include <Components/Collider.h>

Args::SceneSystem::SceneSystem()
{

}

void Args::SceneSystem::Update(float deltaTime)
{
	SceneComponent* sceneManager = GetGlobalComponent<SceneComponent>();
	if (sceneManager->nextScene != "null")
	{
		LoadScene(sceneManager->nextScene);
		sceneManager->nextScene = "null";
	}
}

void Args::SceneSystem::Init()
{
#pragma region Material things
	Args::Texture::CreateTexture("Default", "Default/default-albedo.png");

	Args::Texture::CreateTexture("DefaultAlbedo", "Default/default-albedo.png");
	Args::Texture::CreateTexture("DefaultAo", "Default/default-ao.png");
	Args::Texture::CreateTexture("DefaultHeight", "Default/default-height.png");
	Args::Texture::CreateTexture("DefaultMetal", "Default/default-metal.png");
	Args::Texture::CreateTexture("DefaultNormal", "Default/default-normal.png");
	Args::Texture::CreateTexture("DefaultRoughness", "Default/default-roughness.png");
	Args::Texture::CreateTexture("DefaultEmissive", "Default/default-emissive.png");

	Args::Texture::CreateTexture("GigbitAlbedo", "Gigbit/Gigbit_Model_1001_BaseColor.png");
	Args::Texture::CreateTexture("GigbitAo", "Gigbit/Gigbit_Model_1001_Ao.png");
	Args::Texture::CreateTexture("GigbitHeight", "Gigbit/Gigbit_Model_1001_Height.png");
	Args::Texture::CreateTexture("GigbitMetal", "Gigbit/Gigbit_Model_1001_Metallic.png");
	Args::Texture::CreateTexture("GigbitNormal", "Gigbit/Gigbit_Model_1001_Normal.png");
	Args::Texture::CreateTexture("GigbitRoughness", "Gigbit/Gigbit_Model_1001_Roughness.png");
	Args::Texture::CreateTexture("GigbitEmissive", "Gigbit/Gigbit_Model_1001_Emissive.png");

	Args::Shader::CreateShader("PBRShader", "PBR.vert", "PBR.frag");


	Args::Material* gigbitMaterial = Args::Material::CreateMaterial("GigbitMat", Args::Shader::GetShader("PBRShader"));
	gigbitMaterial->SetTexture("albedoMap", Args::Texture::GetTexture("GigbitAlbedo"));
	gigbitMaterial->SetTexture("aoMap", Args::Texture::GetTexture("GigbitAo"));
	gigbitMaterial->SetTexture("heightMap", Args::Texture::GetTexture("GigbitHeight"));
	gigbitMaterial->SetTexture("metalMap", Args::Texture::GetTexture("GigbitMetal"));
	gigbitMaterial->SetTexture("normalMap", Args::Texture::GetTexture("GigbitNormal"));
	gigbitMaterial->SetTexture("roughnessMap", Args::Texture::GetTexture("GigbitRoughness"));
	gigbitMaterial->SetTexture("emissiveMap", Args::Texture::GetTexture("GigbitEmissive"));
	gigbitMaterial->SetParam<float>("heightScale", 1.f);

	Args::Material* pbrMaterial = Args::Material::CreateMaterial("PBRMat", Args::Shader::GetShader("PBRShader"));
	pbrMaterial->SetTexture("albedoMap", Args::Texture::GetTexture("DefaultAlbedo"));
	pbrMaterial->SetTexture("aoMap", Args::Texture::GetTexture("DefaultAo"));
	pbrMaterial->SetTexture("heightMap", Args::Texture::GetTexture("DefaultHeight"));
	pbrMaterial->SetTexture("metalMap", Args::Texture::GetTexture("DefaultMetal"));
	pbrMaterial->SetTexture("normalMap", Args::Texture::GetTexture("DefaultNormal"));
	pbrMaterial->SetTexture("roughnessMap", Args::Texture::GetTexture("DefaultRoughness"));
	pbrMaterial->SetTexture("emissiveMap", Args::Texture::GetTexture("DefaultEmissive"));
	pbrMaterial->SetParam<float>("heightScale", 1.f);

	Args::Mesh::CreateMesh("TestMesh", "Cube.obj");
	Args::Mesh::CreateMesh("Plane", "plane.obj");
	Args::Mesh::CreateMesh("TestMeshSphere", "UVSphereSmooth.obj");
	Args::Mesh::CreateMesh("Gigbit", "Gigbit_model/Gigbit_model.obj");

	Args::Shader::CreateShader("ColorShader", "color.vert", "color.frag");
	Args::Material* testMaterial = Args::Material::CreateMaterial("testMaterial", Args::Shader::GetShader("ColorShader"));
	testMaterial->SetParam<Args::Vector4>("diffuseColor", Args::Vector4(0.f, 1.f, 0.f, 1.f));

#pragma endregion
	SceneComponent* sceneManager = GetGlobalComponent<SceneComponent>();
	sceneManager->nextScene = "null";
	//LoadScene("SampleScene");
	//LoadScene("OtherScene");
	LoadScene("Level 1");
}

void Args::SceneSystem::LoadScene(std::string fileName)
{
	Debug::Log(DebugInfo, "Loading Scene");
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
					//Debug::Log(DebugInfo, "rot x is float:%f",components[i]["rotation"]["x"].GetFloat()/2.f);
					float x, y, z;
					x = components[i]["rotation"]["x"].GetFloat();// / 2.491f;
					y = components[i]["rotation"]["y"].GetFloat();// / 2.491f;
					z = components[i]["rotation"]["z"].GetFloat();// / 2.491f;
					Debug::Log(DebugInfo, "X:%f,Y:%f,Z:%f", x, y, z);
					//transform->SetRotation(Args::Quaternion(components[i]["rotation"]["x"].GetFloat(), components[i]["rotation"]["y"].GetFloat(), components[i]["rotation"]["z"].GetFloat(), 1));

					/*Args::Matrix3 rotMatX(Args::Vector3(1, 0, 0), Args::Vector3(0, Args::cos(x) ,-Args::sin(x)), Args::Vector3(0,Args::sin(x),Args::cos(x)));
					Args::Matrix3 rotMatY(Args::Vector3(Args::cos(y),0,Args::sin(y)),Args::Vector3(0,1,0),Args::Vector3(-Args::sin(y),0,Args::cos(y)));
					Args::Matrix3 rotMatZ(Args::Vector3(Args::cos(z),-Args::sin(z),0),Args::Vector3(Args::sin(z),Args::cos(z),0),Args::Vector3(0,0,1));*/
					//Args::Matrix3 rotMat = rotMatX*rotMatY*rotMatZ;
					
					Args::Matrix3 rotMat = glm::eulerAngleXYZ(radians(x), radians(y), radians(z));
					transform->SetRotation(rotMat);

					//Set Scale
					assert(components[i]["scale"].IsObject());
					Debug::Log(DebugInfo, "Components[%i] scale isObject", i);
					//auto scale = components[i]["scale"].GetArray();
					assert(components[i]["scale"]["x"].IsFloat());
					Debug::Log(DebugInfo, "scale x is float");
					transform->Scale(Args::Vec3(components[i]["scale"]["x"].GetFloat()/2.f, components[i]["scale"]["y"].GetFloat()/2.f, components[i]["scale"]["z"].GetFloat()/2.f));
				}
				else if (name._Equal("Renderable"))
				{
					//Create Mesh
					Args::Renderable* renderable;
					componentManager->AddComponent<Args::Renderable>(entity, &renderable);
					assert(components[i]["mesh"].IsString());
					Debug::Log(DebugInfo, "Components[%i] Mesh mesh is string", i);
					std::string meshName = components[i]["mesh"].GetString();
					Args::Mesh::CreateMesh(meshName, meshName + "/" + meshName + ".obj");
					renderable->SetMesh(meshName);

					assert(components[i]["material"].IsString());
					Debug::Log(DebugInfo, "Components[%i] Mesh material is string", i);
					std::string matName = components[i]["material"].GetString();
					Args::Texture::CreateTexture("Albedo", meshName+"/"+components[i]["albedo"].GetString()+".png");
					Args::Texture::CreateTexture("Ao", meshName + "/" + components[i]["ao"].GetString() + ".png");
					Args::Texture::CreateTexture("Height", meshName + "/" + components[i]["height"].GetString() + ".png");
					Args::Texture::CreateTexture("Metal", meshName + "/" + components[i]["metal"].GetString() + ".png");
					Args::Texture::CreateTexture("Normal", meshName + "/" + components[i]["normal"].GetString() + ".png");
					Args::Texture::CreateTexture("Roughness", meshName + "/" + components[i]["roughness"].GetString() + ".png");
					Args::Texture::CreateTexture("Emissive", meshName + "/" + components[i]["emissive"].GetString() + ".png");
					Args::Material* pbrMaterial = Args::Material::CreateMaterial("PBRMat", Args::Shader::GetShader("PBRShader"));
					pbrMaterial->SetTexture("albedoMap", Args::Texture::GetTexture("Albedo"));
					pbrMaterial->SetTexture("aoMap", Args::Texture::GetTexture("Ao"));
					pbrMaterial->SetTexture("heightMap", Args::Texture::GetTexture("Height"));
					pbrMaterial->SetTexture("metalMap", Args::Texture::GetTexture("Metal"));
					pbrMaterial->SetTexture("normalMap", Args::Texture::GetTexture("Normal"));
					pbrMaterial->SetTexture("roughnessMap", Args::Texture::GetTexture("Roughness"));
					pbrMaterial->SetTexture("emissiveMap", Args::Texture::GetTexture("Emissive"));
					pbrMaterial->SetParam<float>("heightScale", 1.f);
					renderable->SetMaterial("PBRMat");


				}
				//else if (name._Equal("Rigidbody"))
				//{
				//	//Create Rigibody
				//	Args::Rigidbody* rigidbody;
				//	componentManager->AddComponent<Args::Rigidbody>(entity, &rigidbody);
				//}
				//else if (name._Equal("SphereCollider"))
				//{
				//	//Create SphereCollider
				//	Args::Collider* collider;
				//	componentManager->AddComponent<Args::Collider>(entity, &collider);
				//	float x, y, z;
				//	x = components[i]["center"]["x"].GetFloat();
				//	y = components[i]["center"]["y"].GetFloat();
				//	z = components[i]["center"]["z"].GetFloat();
				//	collider->origin = Args::Vector3(x,y,z);
				//	collider->size = Args::Vector3(components[i]["radius"].GetFloat(),0.f,0.f);
				//}
				//else if (name._Equal("BoxCollider"))
				//{
				//	//Create BoxCollider
				//	Args::Collider* collider;
				//	componentManager->AddComponent<Args::Collider>(entity, &collider);
				//	float x, y, z;
				//	x = components[i]["center"]["x"].GetFloat();
				//	y = components[i]["center"]["y"].GetFloat();
				//	z = components[i]["center"]["z"].GetFloat();
				//	collider->origin = Args::Vector3(x, y, z);
				//	collider->size = Args::Vector3(components[i]["size"]["x"].GetFloat(), components[i]["size"]["y"].GetFloat(), components[i]["size"]["z"].GetFloat());
				//}
				//else if (name._Equal("Light"))
				//{
				//	//Create Light
				//	Args::Light* light;
				//	componentManager->AddComponent<Args::Light>(entity, &light);
				//	light->SetColour(Args::Vector3(1.0));
				//	////Get Light type
				//	//assert(components[i]["type"].IsInt());
				//	////Debug::Log(DebugInfo, "Components[%i] Light type is int", i);
				//	//int type = components[i]["type"].GetInt();
				//	//switch (type)
				//	//{
				//	//case 0:
				//	//	light->SetType(Args::LightType::POINT);
				//	//	break;
				//	//case 1:
				//	//	light->SetType(Args::LightType::DIRECTIONAL);
				//	//	break;
				//	//case 2:
				//	//	light->SetType(Args::LightType::SPOT);
				//	//	break;
				//	//}
				//}
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
		if (object["components"][0]["children"].IsArray())
		{
			Debug::Log(DebugInfo, "Start Deserialize Children");
			const Value& children = object["components"][0]["children"];
			for (SizeType j = 0; j < children.GetArray().Size(); j++)
			{
				const Value& childComps = children[j]["components"];
				auto childComponents = childComps.GetArray();
				Debug::Log(DebugInfo, "%s", children[j]["name"].GetString());
				Debug::Log(DebugInfo, "%i", children.Size());
				Args::uint32 childEntity = componentManager->CreateEntity();
				for (SizeType i = 0; i < childComponents.Size(); i++)
				{
					Debug::Log(DebugInfo, "\t\t\t%s", childComponents[i]["name"].GetString());
					std::string name = childComponents[i]["name"].GetString();
					if (name._Equal("Transform"))
					{
						//Create Transform
						Args::Transform* transform;
						componentManager->AddComponent<Args::Transform>(childEntity, &transform);

						//Set Position
						assert(childComponents[i]["position"].IsObject());
						Debug::Log(DebugInfo, "Child Components[%i] position isObject", i);
						//auto vec = components[i]["position"];
						assert(childComponents[i]["position"]["x"].IsFloat());
						Debug::Log(DebugInfo, "vec x is float");
						transform->SetPosition(Args::Vec3(childComponents[i]["position"]["x"].GetFloat(), childComponents[i]["position"]["y"].GetFloat(), childComponents[i]["position"]["z"].GetFloat()));

						//Set Rotation
						assert(childComponents[i]["rotation"].IsObject());
						Debug::Log(DebugInfo, "CHild Components[%i] rotation isObject", i);
						//auto rot = components[i]["rotation"].GetArray();
						assert(childComponents[i]["rotation"]["x"].IsFloat());
						Debug::Log(DebugInfo, "rot x is float");
						transform->SetRotation(Args::Quaternion(childComponents[i]["rotation"]["x"].GetFloat(), childComponents[i]["rotation"]["y"].GetFloat(), childComponents[i]["rotation"]["z"].GetFloat(), 1));

						//Set Scale
						assert(childComponents[i]["scale"].IsObject());
						Debug::Log(DebugInfo, "Child Components[%i] scale isObject", i);
						//auto scale = components[i]["scale"].GetArray();
						assert(childComponents[i]["scale"]["x"].IsFloat());
						Debug::Log(DebugInfo, "scale x is float");
						transform->SetScale(Args::Vec3(childComponents[i]["scale"]["x"].GetFloat() / 2.0f, childComponents[i]["scale"]["y"].GetFloat() / 2.0f, childComponents[i]["scale"]["z"].GetFloat() / 2.0f));
					}
					else if (name._Equal("Renderable"))
					{
						//Create Mesh
						Args::Renderable* renderable;
						componentManager->AddComponent<Args::Renderable>(entity, &renderable);
						assert(childComponents[i]["mesh"].IsString());
						Debug::Log(DebugInfo, "Components[%i] Mesh mesh is string", i);
						std::string meshName = childComponents[i]["mesh"].GetString();
						Args::Mesh::CreateMesh(meshName, meshName + "/" + meshName + ".obj");
						renderable->SetMesh(meshName);

						assert(childComponents[i]["material"].IsString());
						Debug::Log(DebugInfo, "Components[%i] Mesh material is string", i);
						std::string matName = childComponents[i]["material"].GetString();
						Args::Texture::CreateTexture("Albedo", meshName + "/" + childComponents[i]["albedo"].GetString() + ".png");
						Args::Texture::CreateTexture("Ao", meshName + "/" + childComponents[i]["ao"].GetString() + ".png");
						Args::Texture::CreateTexture("Height", meshName + "/" + childComponents[i]["height"].GetString() + ".png");
						Args::Texture::CreateTexture("Metal", meshName + "/" + childComponents[i]["metal"].GetString() + ".png");
						Args::Texture::CreateTexture("Normal", meshName + "/" + childComponents[i]["normal"].GetString() + ".png");
						Args::Texture::CreateTexture("Roughness", meshName + "/" + childComponents[i]["roughness"].GetString() + ".png");
						Args::Texture::CreateTexture("Emissive", meshName + "/" + childComponents[i]["emissive"].GetString() + ".png");
						Args::Material* pbrMaterial = Args::Material::CreateMaterial("PBRMat", Args::Shader::GetShader("PBRShader"));
						pbrMaterial->SetTexture("albedoMap", Args::Texture::GetTexture("Albedo"));
						pbrMaterial->SetTexture("aoMap", Args::Texture::GetTexture("Ao"));
						pbrMaterial->SetTexture("heightMap", Args::Texture::GetTexture("Height"));
						pbrMaterial->SetTexture("metalMap", Args::Texture::GetTexture("Metal"));
						pbrMaterial->SetTexture("normalMap", Args::Texture::GetTexture("Normal"));
						pbrMaterial->SetTexture("roughnessMap", Args::Texture::GetTexture("Roughness"));
						pbrMaterial->SetTexture("emissiveMap", Args::Texture::GetTexture("Emissive"));
						pbrMaterial->SetParam<float>("heightScale", 1.f);
						renderable->SetMaterial("PBRMat");
					}
					//else if (name._Equal("Rigidbody"))
					//{
					//	//Create Rigibody
					//	//Args::Rigidbody* rigidbody;
					//	//componentManager->AddComponent<Args::Rigidbody>(childEntity, &rigidbody);
					//}
					//else if (name._Equal("SphereCollider"))
					//{
					//	//Create SphereCollider
					//	//Args::Collider* collider;
					//	//componentManager->AddComponent<Args::Collider>(childEntity, &collider);
					//}
					//else if (name._Equal("BoxCollider"))
					//{
					//	//Create BoxCollider
					//	//Args::Collider* collider;
					//	//componentManager->AddComponent<Args::Collider>(childEntity, &collider);
					//}
					//else if (name._Equal("Light"))
					//{
					//	//Creat Light
					//	Args::Light* light;
					//	componentManager->AddComponent<Args::Light>(childEntity, &light);
					//	light->SetColour(Args::Vector3(1.0));
					//	//Get Light type
					//	/*Debug::Log(DebugInfo, "%i", childComponents[i]["type"].GetInt());
					//	assert(childComponents[i]["type"].IsInt());
					//	Debug::Log(DebugInfo, "Components[%i] Light type is int", i);
					//	int type = childComponents[i]["type"].GetInt();
					//	switch (type)
					//	{
					//	case 0:
					//		light->SetType(Args::LightType::DIRECTIONAL);
					//		break;
					//	case 1:
					//		light->SetType(Args::LightType::POINT);
					//		break;
					//	case 2:
					//		light->SetType(Args::LightType::SPOT);
					//		break;
					//	}*/
					//}
					else if (name._Equal("Camera"))
					{
						//Create Camera
						Args::Camera* camera;
						componentManager->AddComponent<Args::Camera>(childEntity, &camera);
						camera->projection = Args::perspective(90.f, 1920.f / 1080.f, 0.001f, 1000.f);
					}
					else
					{
						//This will be used to create other known scripts
						Debug::Warning(DebugInfo, "Unsupported Script, Please contact your local developer at +31 0618829295");
					}
				}
			}
		}
		Debug::Log(DebugInfo, "Done...");
		//add object to scene
		index++;
	}
}

void Args::SceneSystem::UnloadScene()
{
	auto toDestroy = GetEntityList();
	for (auto ent : toDestroy)
	{
		componentManager->DestroyEntity(ent);
	}
}


