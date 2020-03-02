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
	class SceneManager
	{
	private:
		static unsigned sceneCount;
	protected:

		//std::unordered_map<unsigned, std::unique_ptr<Scene>> sceneList;
		std::unordered_map<std::string, unsigned> sceneNames;
		std::queue<unsigned> sceneQueue;
		//std::stack<unsigned> activeSceneStack;
		//std::set<unsigned> scenesToUnload;
		unsigned sceneToUnload;
	public:
		SceneManager();

		unsigned LoadScene(std::string json);
		void UnloadScene(unsigned sceneID);
		void AddObjectToScene(unsigned objectID, unsigned sceneID);
		//void PushActiveScene(unsigned sceneID);
		//void PopActiveScene(bool keepLoaded = false);
		//bool PopToScene(unsigned sceneID, bool requeue = false, bool keepLoaded = false, bool skipQueue = true);
		//void EnqueueScene(unsigned sceneID);
		//void SkipQueueScene(unsigned sceneID);
		//bool DequeueScene(unsigned sceneID);
		//bool PushQueuedScene();
		unsigned CurrentScene();
	};
}

