//#pragma once
//#include <unordered_map>
//#include <memory>
//#include <set>
//#include <string>
//#include "Serialisation/Serialisable.h"
//#include "Hierarchy/SceneManager.h"
//
//class SceneManager;
//class Scene : public ISerialisable
//{
//protected:
//	Scene()
//	{
//
//	}
//	~Scene();
//
//	std::set<unsigned> objectIDs;
//	virtual void Init();
//public:
//	virtual ~Scene();
//	const std::string name;
//	//const unsigned id;
//
//	//SceneManager& manager;
//
//	virtual std::string ObjectType() override;
//	virtual bool SetData(const std::string& name, const std::string& value) override;
//	virtual bool GetData(const std::string& name, std::string& value) override;
//};