#include "Hierarchy\SceneManager.h"

Args::SceneManager::SceneManager()
{
}

unsigned Args::SceneManager::LoadScene(std::string json)
{
	Document dom;
	dom.Parse(json.c_str());
	Scene scene(dom);
	scene.Init();
	return scene.id;
}

void Args::SceneManager::UnloadScene(unsigned sceneID)
{
}

void Args::SceneManager::AddObjectToScene(unsigned objectID, unsigned sceneID)
{
}

unsigned Args::SceneManager::CurrentScene()
{
	return 0;
}
