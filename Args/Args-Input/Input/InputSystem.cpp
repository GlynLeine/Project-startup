#include "InputSystem.h"

Args::InputSystem::InputSystem()
{
	jsonLoader = JSONLoader();
	jsonLoader.LoadKeyMap();

	actionMap = std::map<Key, std::list<std::string>>();
	axisMap = std::map<Key, std::map<std::string, float>>();
	events = std::map<std::string, float>();
}

void Args::InputSystem::Start()
{
}

void Args::InputSystem::Update(float deltaTime)
{
}

void Args::InputSystem::Init()
{
}
