#include "InputSystem.h"

Args::InputSystem::InputSystem()
{
	jsonLoader = JSONLoader();
	jsonLoader.LoadKeyMap();

	actionMap = std::map<Key, function<int>>();
	axisMap = std::map<Key, std::map<std::string, float>>();
	events = std::map<std::string, float>();
}

void Args::InputSystem::Start()
{
}

void Args::InputSystem::Init()
{
	BindFunctionToAction(ENTER, TestFunc);
}

void Args::InputSystem::Update(float deltaTime)
{
}

void Args::InputSystem::InvokeInputAction(Key key, bool pressed, ControllerID controllerID)
{
	//IF specified controller
	std::function<void> fn = actionMap[key];
	fn();
}

template<typename T>
void Args::InputSystem::BindFunctionToAction(std::string name, T(*fp)())
{
	actionMap[name] = fp;
}

template<typename T>
void Args::InputSystem::BindFunctionToAction(Key key, T(*fp)())
{
	actionMap[key] = fp;
}

void Args::InputSystem::TestFunc()
{
	Debug::Log(DebugInfo, "Hello World");
}

void Args::InputSystem::MapEventToKeyAction(std::string name, Key key)
{
	events[name] = key;
}

void Args::InputSystem::MapEventToKeyAxis(std::string name, Key key, float value)
{

}


