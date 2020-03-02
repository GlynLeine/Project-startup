#include "Hierarchy/System/Scene.h"


Args::Scene::Scene(Document& dom) : id(id++), doc(dom)
{

}

Args::Scene::~Scene()
{
}

void Args::Scene::Init()
{
	Debug::Log(DebugInfo, "Aserting...");
	assert(doc["Scene"].IsArray());
	Debug::Log(DebugInfo, "...Done!");

	const Value& Scene = doc["Scene"].GetArray();
	SizeType index = 0;
	while (index < Scene.Size())
	{
		const Value& object = Scene[index];
		Args::uint32 entity = ecs.CreateEntity();
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
				if (components[i]["name"].GetString() == "Transform")
				{
					//Create Transform
					Args::Transform* transform;
					ecs.AddComponent<Args::Transform>(entity, &transform);

					//Set Position
					assert(components[i]["position"].IsArray());
					Debug::Log(DebugInfo, "Components[%i] position isArray", i);
					auto vec = components[i]["position"].GetArray();
					assert(vec[0].IsFloat());
					Debug::Log(DebugInfo, "vec is float array");
					transform->SetPosition(Args::Vec3(vec[0].GetFloat(), vec[1].GetFloat(), vec[2].GetFloat()));

					//Set Rotation
					assert(components[i]["rotation"].IsArray());
					Debug::Log(DebugInfo, "Components[%i] rotation isArray", i);
					auto rot = components[i]["rotation"].GetArray();
					assert(rot[0].IsFloat());
					Debug::Log(DebugInfo, "rot is float array");
					transform->SetRotation(Args::Quaternion(rot[0].GetFloat(), rot[1].GetFloat(), rot[2].GetFloat(), rot[3].GetFloat()));

					//Set Scale
					assert(components[i]["scale"].IsArray());
					Debug::Log(DebugInfo, "Components[%i] scale isArray", i);
					auto scale = components[i]["scale"].GetArray();
					assert(scale[0].IsFloat());
					Debug::Log(DebugInfo, "rot is float array");
					transform->SetScale(Args::Vec3(scale[0].GetFloat(), scale[1].GetFloat(), scale[2].GetFloat()));
				}
				else if (components[i]["name"].GetString() == "Mesh")
				{
					//Create Mesh
					Args::Renderable* renderable;
					ecs.AddComponent<Args::Renderable>(entity, &renderable);
					assert(components[i]["name"]["material"].IsString());
					Debug::Log(DebugInfo, "Components[%i] Mesh material is string", i);
					renderable->SetMaterial(components[i]["name"]["material"].GetString());

					assert(components[i]["name"]["mesh"].IsString());
					Debug::Log(DebugInfo, "Components[%i] Mesh mesh is string", i);
					renderable->SetMesh(components[i]["name"]["mesh"].GetString());
				}
				else if (components[i]["name"].GetString() == "Rigidbody")
				{
					//Create Rigibody
					Args::Rigidbody* rigidbody;
					ecs.AddComponent<Args::Rigidbody>(entity, &rigidbody);
				}
				else if (components[i]["name"].GetString() == "SphereCollider")
				{
					//Create SphereCollider
					Args::Collider* collider;
					ecs.AddComponent<Args::Collider>(entity, &collider);
				}
				else if (components[i]["name"].GetString() == "BoxCollider")
				{
					//Create BoxCollider
					Args::Collider* collider;
					ecs.AddComponent<Args::Collider>(entity, &collider);
				}
				else if (components[i]["name"].GetString() == "Light")
				{
					//Creat Light
					Args::Light* light;
					ecs.AddComponent<Args::Light>(entity, &light);

					//Get Light type
					assert(components[i]["name"]["type"].IsInt());
					Debug::Log(DebugInfo, "Components[%i] Light type is int", i);
					int type = components[i]["name"]["type"].GetInt();
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
				else if (components[i]["name"].GetString() == "Camera")
				{
					//Create Camera
					Args::Camera* camera;
					ecs.AddComponent<Args::Camera>(entity, &camera);
					camera->projection = Args::perspective(90.f, 1920.f / 1080.f, 0.001f, 1000.f);
				}
				else
				{
					//This will be used to create other known scripts
					Debug::Error(DebugInfo, "Unsupported Script, Please contact your local developer at +31 0618829295");
				}
			}
		}
		Debug::Log(DebugInfo, "Done...");
		//add object to scene
		AddObject(entity);
		index++;
	}
}

bool Args::Scene::SetData(const std::string& name, const std::string& value)
{
	return false;
}

bool Args::Scene::GetData(const std::string& name, std::string& value)
{
	return false;
}

void Args::Scene::AddObject(unsigned id)
{
	objectIDs.push_back(id);
}

void Args::Scene::Unload()
{
}
