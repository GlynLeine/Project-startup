#include "Hierarchy/System/SceneSystem.h"

Args::SceneSystem::SceneSystem()
{

}

unsigned Args::SceneSystem::LoadScene(std::string fileName)
{
	SceneComponent* sceneManager = GetGlobalComponent<SceneComponent>();
	std::string json;
	sceneManager->jsonLoader.LoadSceneFile(fileName);
	Document dom;
	dom.Parse(json.c_str());
	Scene* scene = new Scene(dom);
	scene->Init();
	sceneManager->sceneList[scene->id] = scene;
	return scene->id;
}

void Args::SceneSystem::UnloadScene(unsigned sceneID)
{

}

void Args::SceneSystem::AddObjectToScene(unsigned objectID, unsigned sceneID)
{
}

unsigned Args::SceneSystem::CurrentScene()
{
	return 0;
}
