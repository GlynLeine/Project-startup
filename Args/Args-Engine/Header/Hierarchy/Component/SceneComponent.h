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
#include <rapidjson/document.h>
#include <Serialisation/JSONLoader.h>
namespace Args
{
	struct SceneComponent : public GlobalComponent<SceneComponent>
	{
	public:
		friend class SceneSystem;

		JSONLoader jsonLoader;
		std::vector<unsigned> sceneList;
		std::unordered_map<std::string, unsigned> sceneNames;
		unsigned sceneToUnload;
		static unsigned sceneCount;

		// Inherited via GlobalComponent
		virtual std::string ObjectType() override;
		virtual bool SetData(const std::string& name, const std::string& value) override;
		virtual bool GetData(const std::string& name, std::string& value) override;
	};
}