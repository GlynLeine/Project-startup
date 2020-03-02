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
#include "Hierarchy/System/Scene.h"
#include <rapidjson/document.h>
namespace Args
{
	struct SceneComponent : public GlobalComponent<SceneComponent>
	{
	public:
		friend class SceneSystem;

		JSONLoader jsonLoader;
		std::unordered_map<unsigned, Scene*> sceneList;
		std::unordered_map<std::string, unsigned> sceneNames;
		unsigned sceneToUnload;
		static unsigned sceneCount;
	};
}