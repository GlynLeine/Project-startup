#pragma once
#include <unordered_map>
#include <memory>
#include <set>
#include <string>
#include "Serialisation/Serialisable.h"
#include <rapidjson/document.h>
#include <Args-Core.h>
#include <Args-Physics.h>
#include <Args-Rendering.h>
#include <Args-Math.h>
#include <Args-Window.h>
#include <Args-Input.h>
#include <Components/Rigidbody.h>
#include <Components/Collider.h>

using namespace rapidjson;
namespace Args
{
	class Scene : public ISerialisable
	{
	public:
		Scene(Document& dom);
		std::vector<unsigned> objectIDs;
		virtual void Init();
		virtual ~Scene();
		const std::string name;
		unsigned id = -1;
		Document& doc;
		ECS ecs;

		//SceneManager& manager;

		virtual std::string ObjectType() override;
		virtual bool SetData(const std::string& name, const std::string& value) override;
		virtual bool GetData(const std::string& name, std::string& value) override;
		void AddObject(unsigned id);
		void Unload();
	};
}