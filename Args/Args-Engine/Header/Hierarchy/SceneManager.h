#pragma once
#include <unordered_map>
#include <queue>
#include <stack>
#include <memory>
#include <set>
#include <string>
#include "Hierarchy/Scene.h"
#include <rapidjson/document.h>

using namespace rapidjson;
namespace Args
{
	class SceneManager : public MonoUpdateSystem<SceneManager>
	{
	public:
		SceneManager();
		JSONLoader jsonLoader;
		unsigned LoadScene(std::string json);
		void UnloadScene(unsigned sceneID);
		void AddObjectToScene(unsigned objectID, unsigned sceneID);
		unsigned CurrentScene();
	};
}

