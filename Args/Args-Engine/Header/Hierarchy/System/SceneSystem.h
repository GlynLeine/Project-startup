#pragma once
#include <unordered_map>
#include <queue>
#include <stack>
#include <memory>
#include <set>
#include <string>
#include "Hierarchy/System/Scene.h"
#include <rapidjson/document.h>
#include <Hierarchy/Component/SceneComponent.h>

using namespace rapidjson;
namespace Args
{
	class SceneSystem : public MonoUpdateSystem<SceneSystem>
	{
	public:
		SceneSystem();
		unsigned LoadScene(std::string json);
		void UnloadScene(unsigned sceneID);
		void AddObjectToScene(unsigned objectID, unsigned sceneID);
		unsigned CurrentScene();
	};
}

