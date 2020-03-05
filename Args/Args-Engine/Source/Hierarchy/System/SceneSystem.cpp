#include "Hierarchy/System/SceneSystem.h"
#include <Components/AudioListener.h>
#include <Components\AudioSource.h>

Args::SceneSystem::SceneSystem()
{

}



void Args::SceneSystem::Init()
{


	
#pragma region Default
	Args::Texture::CreateTexture("Default", "Default/default-albedo.png");
	Args::Texture::CreateTexture("DefaultAlbedo", "Default/default-albedo.png");
	Args::Texture::CreateTexture("DefaultAo", "Default/default-ao.png");
	Args::Texture::CreateTexture("DefaultHeight", "Default/default-height.png");
	Args::Texture::CreateTexture("DefaultMetal", "Default/default-metal.png");
	Args::Texture::CreateTexture("DefaultNormal", "Default/default-normal.png");
	Args::Texture::CreateTexture("DefaultRoughness", "Default/default-roughness.png");
	Args::Texture::CreateTexture("DefaultEmissive", "Default/default-emissive.png");

	Args::Shader::CreateShader("PBRShader", "PBR.vert", "PBR.frag");
	Args::Shader::CreateShader("ColorShader", "color.vert", "color.frag");

	Args::Material* pbrMaterial = Args::Material::CreateMaterial("PBRMat", Args::Shader::GetShader("PBRShader"));
	pbrMaterial->SetTexture("albedoMap", Args::Texture::GetTexture("DefaultAlbedo"));
	pbrMaterial->SetTexture("aoMap", Args::Texture::GetTexture("DefaultAo"));
	pbrMaterial->SetTexture("heightMap", Args::Texture::GetTexture("DefaultHeight"));
	pbrMaterial->SetTexture("metalMap", Args::Texture::GetTexture("DefaultMetal"));
	pbrMaterial->SetTexture("normalMap", Args::Texture::GetTexture("DefaultNormal"));
	pbrMaterial->SetTexture("roughnessMap", Args::Texture::GetTexture("DefaultRoughness"));
	pbrMaterial->SetTexture("emissiveMap", Args::Texture::GetTexture("DefaultEmissive"));
	pbrMaterial->SetParam<float>("heightScale", 1.f);
#pragma endregion
#pragma region Gigbit
	Args::Texture::CreateTexture("GigbitAlbedo", "Gigbit/Gigbit_Model_1001_BaseColor.png");
	Args::Texture::CreateTexture("GigbitAo", "Gigbit/Gigbit_Model_1001_Ao.png");
	Args::Texture::CreateTexture("GigbitHeight", "Gigbit/Gigbit_Model_1001_Height.png");
	Args::Texture::CreateTexture("GigbitMetal", "Gigbit/Gigbit_Model_1001_Metallic.png");
	Args::Texture::CreateTexture("GigbitNormal", "Gigbit/Gigbit_Model_1001_Normal.png");
	Args::Texture::CreateTexture("GigbitRoughness", "Gigbit/Gigbit_Model_1001_Roughness.png");
	Args::Texture::CreateTexture("GigbitEmissive", "Gigbit/Gigbit_Model_1001_Emissive.png");



	Args::Material* gigbitMaterial = Args::Material::CreateMaterial("GigbitMat", Args::Shader::GetShader("PBRShader"));
	gigbitMaterial->SetTexture("albedoMap", Args::Texture::GetTexture("GigbitAlbedo"));
	gigbitMaterial->SetTexture("aoMap", Args::Texture::GetTexture("GigbitAo"));
	gigbitMaterial->SetTexture("heightMap", Args::Texture::GetTexture("GigbitHeight"));
	gigbitMaterial->SetTexture("metalMap", Args::Texture::GetTexture("GigbitMetal"));
	gigbitMaterial->SetTexture("normalMap", Args::Texture::GetTexture("GigbitNormal"));
	gigbitMaterial->SetTexture("roughnessMap", Args::Texture::GetTexture("GigbitRoughness"));
	gigbitMaterial->SetTexture("emissiveMap", Args::Texture::GetTexture("GigbitEmissive"));
	gigbitMaterial->SetParam<float>("heightScale", 1.f);
#pragma endregion
#pragma region Meshes
	Args::Mesh::CreateMesh("TestMesh", "Cube.obj");
	Args::Mesh::CreateMesh("Plane", "Plane.obj");
	Args::Mesh::CreateMesh("TestMeshSphere", "UVSphereSmooth.obj");
	Args::Mesh::CreateMesh("pCube22_pCube22", "Gigbit/Gigbit_model.obj");
	Args::Mesh::CreateMesh("AntiShoplifting_model","anti theft/AntiShoplifting_model.obj");
	Args::Mesh::CreateMesh("scaled_button","button/scaled_button.obj");
	Args::Mesh::CreateMesh("fence_model", "fence/fence_model.obj");	
	Args::Mesh::CreateMesh("garbage can closed", "garbage can closed/garbage can closed.obj");
	Args::Mesh::CreateMesh("garbage can open", "garbage can open/garbage can open.obj");
	Args::Mesh::CreateMesh("gate_1", "gate 1/gate_1_model.obj");
	Args::Mesh::CreateMesh("gate_2", "gate 2/gate_2_model.obj");
	Args::Mesh::CreateMesh("wall_model", "normal wall/wall_model.obj");
	Args::Mesh::CreateMesh("PressurePlate_model", "pressure plate/PressurePlate_model.obj");
	Args::Mesh::CreateMesh("block_model", "scrapmetal piles/block/block_model.obj");
	Args::Mesh::CreateMesh("elevated block_model", "scrapmetal piles/elevated block/elevated block_model.obj");
	Args::Mesh::CreateMesh("long pole_model", "scrapmetal piles/long pole/long pole_model.obj");
	Args::Mesh::CreateMesh("rectangular block_model", "scrapmetal piles/rect block/rectangular block_model.obj");
	Args::Mesh::CreateMesh("rounded pipe_model", "scrapmetal piles/rounded pipe/rounded pipe_model.obj");
	Args::Mesh::CreateMesh("screw_model", "scrapmetal piles/screw/screw_model.obj");
	Args::Mesh::CreateMesh("short pole model", "scrapmetal piles/short pipe/short pole model.obj");
	Args::Mesh::CreateMesh("spike flat top model", "scrapmetal piles/spike flat top/spike flat top model.obj");
	Args::Mesh::CreateMesh("spiky spike model", "scrapmetal piles/spiky spike/spiky spike model.obj");
	Args::Mesh::CreateMesh("standing pipe model", "scrapmetal piles/standing pipe/standing pipe model.obj");
	Args::Mesh::CreateMesh("pCube7_pCube7", "scrappy/Scrappy model.obj");
	Args::Mesh::CreateMesh("window_1_model", "window 1/window_1_model.obj");
	Args::Mesh::CreateMesh("window_2_model", "window 2/window_2_model.obj");
	Args::Mesh::CreateMesh("g_pCube1_pCube1","Cube.obj");
#pragma endregion

	Args::Material* testMaterial = Args::Material::CreateMaterial("testMaterial", Args::Shader::GetShader("ColorShader"));
	testMaterial->SetParam<Args::Vector4>("diffuseColor", Args::Vector4(0.f, 1.f, 0.f, 1.f));

	Args::SceneComponent* sceneComponent = GetGlobalComponent<SceneComponent>();
	sceneComponent->sceneNames[0] = "Level 1";
	sceneComponent->sceneNames[1] = "Level 2";
	sceneComponent->sceneNames[2] = "Level 3";
	sceneComponent->sceneNames[3] = "Level 4";
	sceneComponent->sceneToLoad = 0;
	LoadSceneByNum(sceneComponent->sceneToLoad);
}

void Args::SceneSystem::LoadSceneByNum(unsigned id)
{
	Args::SceneComponent* sceneComponent = GetGlobalComponent<SceneComponent>();
	LoadScene(sceneComponent->sceneNames[id]);
}

unsigned Args::SceneSystem::LoadScene(std::string fileName)
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
					assert(components[i]["rotation"]["x"].IsFloat());
					//Debug::Log(DebugInfo, "rot x is float:%f",components[i]["rotation"]["x"].GetFloat()/2.f);
					float x, y, z;
					x = components[i]["rotation"]["x"].GetFloat();// / 2.491f;
					y = components[i]["rotation"]["y"].GetFloat();// / 2.491f;
					z = components[i]["rotation"]["z"].GetFloat();// / 2.491f;
					Debug::Log(DebugInfo, "X:%f,Y:%f,Z:%f", x, y, z);

					Args::Matrix3 rotMat = glm::eulerAngleXYZ(radians(x), radians(y), radians(z));
					transform->SetRotation(rotMat);

					//Set Scale
					assert(components[i]["scale"].IsObject());
					Debug::Log(DebugInfo, "Components[%i] scale isObject", i);
					//auto scale = components[i]["scale"].GetArray();
					assert(components[i]["scale"]["x"].IsFloat());
					Debug::Log(DebugInfo, "scale x is float");
					transform->Scale(Args::Vec3(components[i]["scale"]["x"].GetFloat(), components[i]["scale"]["y"].GetFloat(), components[i]["scale"]["z"].GetFloat()));
				}
				else if (name._Equal("MeshFilter"))
				{
					//Create Mesh
					Args::Renderable* renderable;
					componentManager->AddComponent<Args::Renderable>(entity, &renderable);
					assert(components[i]["material"].IsString());
					Debug::Log(DebugInfo, "Components[%i] Mesh material is string", i);
					std::string matName = components[i]["material"].GetString();
					renderable->SetMaterial("GigbitMat");

					assert(components[i]["mesh"].IsString());
					Debug::Log(DebugInfo, "Components[%i] Mesh mesh is string", i);
					std::string meshName = components[i]["mesh"].GetString();
					renderable->SetMesh(meshName);
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
					//Args::Collider* collider;
					//componentManager->AddComponent<Args::Collider>(entity, &collider);
				}
				else if (name._Equal("BoxCollider"))
				{
					//Create BoxCollider
					//Args::Collider* collider;
					//componentManager->AddComponent<Args::Collider>(entity, &collider);
				}
				else if (name._Equal("Light"))
				{
					//Create Light
					Args::Light* light;
					componentManager->AddComponent<Args::Light>(entity, &light);
					light->SetColour(Args::Vector3(1.0));
					//Get Light type
					assert(components[i]["type"].IsInt());
					//Debug::Log(DebugInfo, "Components[%i] Light type is int", i);
					int type = components[i]["type"].GetInt();
					switch (type)
					{
					case 0:
						light->SetType(Args::LightType::POINT);
						break;
					case 1:
						light->SetType(Args::LightType::DIRECTIONAL);
						break;
					case 2:
						light->SetType(Args::LightType::SPOT);
						break;
					}
				}
				else if (name._Equal("AudioListener"))
				{
					//Create AudioListener
					componentManager->AddComponent<Args::AudioListener>(entity);
				}
				else if (name._Equal("AudioSource"))
				{
					//Create AudioSource
					Args::AudioSource* audioSource;
					componentManager->AddComponent<Args::AudioSource>(entity, &audioSource);
					audioSource->Load(components[i]["clipname"].GetString(), components[i]["loop"].GetBool());
					if (components[i]["playOnAwake"].GetBool())
					{
						audioSource->Play();
					}
				}
				else if (components[i]["name"].GetString() == "Camera")
				{
					//Create Camera
					Args::Camera* camera;
					componentManager->AddComponent<Args::Camera>(entity, &camera);
					camera->projection = Args::perspective(90.f, 1920.f / 1080.f, 0.001f, 1000.f);
				}
				else if (name._Equal("Movement"))
				{
					Debug::Log(DebugInfo, "Added Movement");
				}
				else if (name._Equal("Movement2"))
				{
					Debug::Log(DebugInfo, "Added Movement2");
				}
				else if (name._Equal("Player"))
				{
					Debug::Log(DebugInfo, "Added Player");
				}
				else if (name._Equal("groundCheck"))
				{
					Debug::Log(DebugInfo, "Added GroundCheck");
				}
				else if (name._Equal("triggerBox"))
				{
					Debug::Log(DebugInfo, "Added Trigger Box");
				}
				else if (name._Equal("Push"))
				{
					Debug::Log(DebugInfo, "Added Push");
				}
				else if (name._Equal("Pick Up"))
				{
					Debug::Log(DebugInfo, "Added Pick Up");
				}
				else if (name._Equal("Door"))
				{
					Debug::Log(DebugInfo, "Added Door");
				}
				else if (name._Equal("End Point"))
				{
					Debug::Log(DebugInfo, "Added Endpoint");
				}
				else
				{
					//This will be used to create other known scripts
					Debug::Warning(DebugInfo, "Unsupported Script: %s, Please contact your local developer at +31 0618829295", name);
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
						float x, y, z;
						x = childComponents[i]["rotation"]["x"].GetFloat();// / 2.491f;
						y = childComponents[i]["rotation"]["y"].GetFloat();// / 2.491f;
						z = childComponents[i]["rotation"]["z"].GetFloat();// / 2.491f;
						Debug::Log(DebugInfo, "X:%f,Y:%f,Z:%f", x, y, z);
						Args::Matrix3 rotMat = glm::eulerAngleXYZ(radians(x), radians(y), radians(z));
						transform->SetRotation(rotMat);
						//transform->SetRotation(Args::Quaternion(childComponents[i]["rotation"]["x"].GetFloat(), childComponents[i]["rotation"]["y"].GetFloat(), childComponents[i]["rotation"]["z"].GetFloat(), 1));

						//Set Scale
						assert(childComponents[i]["scale"].IsObject());
						Debug::Log(DebugInfo, "Child Components[%i] scale isObject", i);
						//auto scale = components[i]["scale"].GetArray();
						assert(childComponents[i]["scale"]["x"].IsFloat());
						Debug::Log(DebugInfo, "scale x is float");
						transform->SetScale(Args::Vec3(childComponents[i]["scale"]["x"].GetFloat() / 2.0f, childComponents[i]["scale"]["y"].GetFloat() / 2.0f, childComponents[i]["scale"]["z"].GetFloat() / 2.0f));
					}
					else if (name._Equal("MeshFilter"))
					{
						//Create Mesh
						Args::Renderable* renderable;
						componentManager->AddComponent<Args::Renderable>(childEntity, &renderable);
						assert(childComponents[i]["material"].IsString());
						Debug::Log(DebugInfo, " Child Components[%i] Mesh material is string", i);
						std::string matName = childComponents[i]["material"].GetString();
						renderable->SetMaterial("GigbitMat");

						assert(childComponents[i]["mesh"].IsString());
						Debug::Log(DebugInfo, "Child Components[%i] Mesh mesh is string", i);
						std::string meshName = childComponents[i]["mesh"].GetString();
						renderable->SetMesh("TestMesh");


					}
					else if (name._Equal("Rigidbody"))
					{
						//Create Rigibody
						//Args::Rigidbody* rigidbody;
						//componentManager->AddComponent<Args::Rigidbody>(childEntity, &rigidbody);
					}
					else if (name._Equal("SphereCollider"))
					{
						//Create SphereCollider
						//Args::Collider* collider;
						//componentManager->AddComponent<Args::Collider>(childEntity, &collider);
					}
					else if (name._Equal("BoxCollider"))
					{
						//Create BoxCollider
						//Args::Collider* collider;
						//componentManager->AddComponent<Args::Collider>(childEntity, &collider);
					}
					else if (name._Equal("Light"))
					{
						//Creat Light
						Args::Light* light;
						componentManager->AddComponent<Args::Light>(childEntity, &light);
						light->SetColour(Args::Vector3(1.0));
						//Get Light type
						assert(childComponents[i]["type"].IsInt());
						Debug::Log(DebugInfo, "Components[%i] Light type is int", i);
						int type = childComponents[i]["type"].GetInt();
						switch (type)
						{
						case 0:
							light->SetType(Args::LightType::DIRECTIONAL);
							break;
						case 1:
							light->SetType(Args::LightType::POINT);
							break;
						case 2:
							light->SetType(Args::LightType::SPOT);
							break;
						}
					}
					else if (name._Equal("Camera"))
					{
						//Create Camera
						Args::Camera* camera;
						componentManager->AddComponent<Args::Camera>(childEntity, &camera);
						camera->projection = Args::perspective(90.f, 1920.f / 1080.f, 0.001f, 1000.f);
					}
					else if (name._Equal("AudioListener"))
					{
						//Create AudioListener
						componentManager->AddComponent<Args::AudioListener>(entity);
					}
					else if (name._Equal("AudioSource"))
					{
						//Create AudioSource
						Args::AudioSource* audioSource;
						componentManager->AddComponent<Args::AudioSource>(entity, &audioSource);
						audioSource->Load(childComponents[i]["clipname"].GetString(), childComponents[i]["loop"].GetBool());
						if (childComponents[i]["playOnAwake"].GetBool())
						{
							audioSource->Play();
						}

					}
					else if (childComponents[i]["name"].GetString() == "Camera")
					{
						//Create Camera
						Args::Camera* camera;
						componentManager->AddComponent<Args::Camera>(entity, &camera);
						camera->projection = Args::perspective(90.f, 1920.f / 1080.f, 0.001f, 1000.f);
					}
					else if (name._Equal("Movement"))
					{
						Debug::Log(DebugInfo, "Added Movement");
					}
					else if (name._Equal("Movement2"))
					{
						Debug::Log(DebugInfo, "Added Movement2");
					}
					else if (name._Equal("Player"))
					{
						Debug::Log(DebugInfo, "Added Player");
					}
					else if (name._Equal("groundCheck"))
					{
						Debug::Log(DebugInfo, "Added GroundCheck");
					}
					else if (name._Equal("triggerBox"))
					{
						Debug::Log(DebugInfo, "Added Trigger Box");
					}
					else if (name._Equal("Push"))
					{
						Debug::Log(DebugInfo, "Added Push");
					}
					else if (name._Equal("Pick Up"))
					{
						Debug::Log(DebugInfo, "Added Pick Up");
					}
					else if (name._Equal("Door"))
					{
						Debug::Log(DebugInfo, "Added Door");
					}
					else if (name._Equal("End Point"))
					{
						Debug::Log(DebugInfo, "Added Endpoint");
					}
					else
					{
						//This will be used to create other known scripts
						Debug::Warning(DebugInfo, "Unsupported Script: %s, Please contact your local developer at +31 0618829295", name);
					}
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
	auto toDestroy = GetEntityList();
	for (auto ent : toDestroy)
	{

	}
}

void Args::SceneSystem::AddObjectToScene(unsigned objectID, unsigned sceneID)
{
}

unsigned Args::SceneSystem::CurrentScene()
{
	return 0;
}


