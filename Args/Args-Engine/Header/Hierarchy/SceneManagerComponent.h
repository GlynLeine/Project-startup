#pragma once
#include<ECS/Component.h>
#include <array>
#include <Args-Math.h>
#include <Utils/Common.h>
#include <vector>
#include <unordered_map>
#include <queue>
#include <stack>
#include <memory>
#include <set>
#include <string>
#include "Hierarchy/Scene.h"
#include <rapidjson/document.h>
namespace Args
{
	struct SceneManagerComponent : public Component<SceneManagerComponent>
	{
	public:
		//std::unordered_map<unsigned, std::unique_ptr<Scene>> sceneList;
		std::unordered_map<std::string, unsigned> sceneNames;
		std::queue<unsigned> sceneQueue;
		//std::stack<unsigned> activeSceneStack;
		//std::set<unsigned> scenesToUnload;
		unsigned sceneToUnload;

		static unsigned sceneCount;
	protected:


	};
}