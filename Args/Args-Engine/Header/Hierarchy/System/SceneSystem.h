#pragma once
#include <unordered_map>
#include <queue>
#include <stack>
#include <memory>
#include <set>
#include <string>
#include <rapidjson/document.h>
#include <Hierarchy/Component/SceneComponent.h>
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
	class SceneSystem : public MonoUpdateSystem<Args::SceneSystem>
	{
	public:
		SceneSystem();
		unsigned LoadScene(std::string json);
		void UnloadScene(unsigned sceneID);
		void AddObjectToScene(unsigned objectID, unsigned sceneID);
		unsigned CurrentScene();

		// Inherited via MonoUpdateSystem
		virtual void Init() override;
	};
}

