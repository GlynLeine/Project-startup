#include "InputSystem.h"

Args::InputSystem::InputSystem()
{
	jsonLoader = JSONLoader();
	jsonLoader.LoadKeyMap("");

	actionMap = std::map<Key, function<void(bool a_pressed, ControllerID a_controllerID)>>();
	axisMap = std::map<Key, std::map<std::string, float>>();
	events = std::map<std::string, float>();
}

void Args::InputSystem::Start()
{

}

void Args::InputSystem::Init()
{
	std::function<void(bool, ControllerID)> func = std::bind(&Args::InputSystem::KeyActionDelegate, this, std::placeholders::_1, std::placeholders::_2);
	std::function<void(bool, ControllerID)> func2 = std::bind(&Args::InputSystem::TestFunc, this, std::placeholders::_1, std::placeholders::_2);
	BindFunctionToAction(ENTER, func2);
}

void Args::InputSystem::Update(float deltaTime)
{
}

void Args::InputSystem::InvokeInputAction(Key key, bool pressed, ControllerID controllerID)
{
	//IF specified controller
	actionMap[key](pressed,controllerID);
}
void Args::InputSystem::BindFunctionToAction(Args::Key key, std::function<void(bool, ControllerID)> func)
{
	actionMap[key] = func;
}

void Args::InputSystem::BindFunctionToAxis(std::string name, std::function<void(float, std::list<ControllerID>)> func)
{
}

void Args::InputSystem::BindFunctionToButtonEvent(std::string name, std::function<void(Key, bool, ControllerID)> func)
{
}

void Args::InputSystem::TestFunc(bool pressed, ControllerID cID)
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


