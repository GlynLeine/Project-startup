#include "Input/InputSystem.h"
#include <GLFW/glfw3.h>

using namespace rapidjson;

void Args::InputSystem::Start()
{
	//mdcclxxvi
}

void Args::InputSystem::Init()
{
	BindForUpdate(std::bind(&InputSystem::Update, this, std::placeholders::_1));
	Engine::BindToEvent<Events::ControllerConnected>(std::bind(&InputSystem::OnControllerConnected,this,std::placeholders::_1));
	//Engine::BindToEvent<Events::ControllerDisconnected>(std::bind(&InputSystem::OnControllerDisconnected, this, std::placeholders::_1));
	jsonLoader = JSONLoader();
	Document dom;
	std::string str = jsonLoader.LoadKeyMap("KeyMapTest.json");
	//Debug::Log(DebugInfo, str);
	const char* toParse = str.c_str();
	dom.Parse(toParse);
	assert(dom.HasMember("KeyMaps"));
	const Value& keyMaps = dom["KeyMaps"];
	//Debug::Log(DebugInfo, "Checking if Array");
	assert(keyMaps.IsArray());
	//Debug::Log(DebugInfo, "Is Array");
	SizeType i = 0;
	for (i = 0; i < keyMaps.Size(); i++)
	{
		//Debug::Log(DebugInfo, "Checking if keyMaps[i] is and Object");
		assert(keyMaps[i].IsObject());
		//Debug::Log(DebugInfo, "True");

		//Debug::Log(DebugInfo, "Checking if keyMaps[i][Pair] is an array");
		assert(keyMaps[i]["Pair"].IsArray());
		//Debug::Log(DebugInfo, "True");

		//Debug::Log(DebugInfo,"Setting pair to pair var");
		const Value& pair = keyMaps[i]["Pair"];
		//Debug::Log(DebugInfo, "Done");

		//Debug::Log(DebugInfo,"Checking if pair is array");
		assert(pair.IsArray());
		//Debug::Log(DebugInfo, "True");

		//Debug::Log(DebugInfo, "Checking if first in Pair is a string");
		assert(pair[0].IsString());
		//Debug::Log(DebugInfo, "True");

		//Debug::Log(DebugInfo, "Checking if second in Pair is a int");
		assert(pair[1].IsString());
		//Debug::Log(DebugInfo, "True");

		buttonMap[enumStorage[pair[1].GetString()]] = pair[0].GetString();
		//Debug::Log(DebugInfo, "i%", buttonMap[pair[0].GetString()]);
	}

	for (int i = 0;i<15;i++)
	{
		keyPressed[i] = false;
	}
	Debug::Success(DebugInfo, "Initialised InputSystem");

	std::function<void()> func = std::bind(&Args::InputSystem::doSomething, this);
	////std::function<void(bool, ControllerID)> func2 = std::bind(&Args::InputSystem::TestFunc, this, std::placeholders::_1, std::placeholders::_2);
	for (int i = 0;i<20;i++)
	{
		BindFunctionToAction(glfwToKey[i], func);
	}
}

void Args::InputSystem::Update(float deltaTime)
{
	//GET INPUT
	RetrieveInput();
	//RESET AXES

	//HANDLE PRESS EVENTS

	//HANDLE RELESSE EVENTS

	//INVOKE AXIS EVENTS
}

void Args::InputSystem::RetrieveInput()
{
	releasedKeys.clear();
	for (int controller = 0;controller<16;controller++)
	{
		if (glfwJoystickIsGamepad(controller/*GLFW_JOYSTICK_1*/))
		{
			if (!isConnected)
			{
				Debug::Log(DebugInfo, "The Joystick is Connected");
			}
			isConnected = true;

			GLFWgamepadstate state;
			if (glfwGetGamepadState(controller/*GLFW_JOYSTICK_1*/, &state))
			{
				for (int i = 0; i < 15; i++)
				{
					if (state.buttons[i] == GLFW_PRESS && !keyPressed[i])
					{
						Debug::Log(DebugInfo, "%u PressStarted", i);
						keyPressed[i] = true;
						pressedKeys[glfwToKey[i]].push_back(controller);
						continue;
					}
					if (state.buttons[i] == GLFW_RELEASE && keyPressed[i])
					{
						Debug::Log(DebugInfo, "%u PressEnded", i);
						keyPressed[i] = false;
						releasedKeys[glfwToKey[i]].push_back(controller);
						continue;
					}
				}
			}
		}
	}
}

void Args::InputSystem::OnControllerConnected(IEvent& event)
{
	Events::ControllerConnected connectionEvent = reinterpret_cast<Events::ControllerConnected&>(event);
	Debug::Log(DebugInfo, "Connected");
}
void Args::InputSystem::WhileControllerConnected(IEvent& event)
{
	Events::ControllerIsConnected connectionEvent = reinterpret_cast<Events::ControllerIsConnected&>(event);
	Debug::Log(DebugInfo, "Still Connected");
}
void Args::InputSystem::OnControllerDisconnected(IEvent& event)
{
	Events::ControllerDisconnected connectionEvent = reinterpret_cast<Events::ControllerDisconnected&>(event);
	Debug::Log(DebugInfo, "Disconnected");
}


void Args::InputSystem::UpdateAxesForKey(Key key, ControllerID controllerID)
{
}
void Args::InputSystem::CreateEvent(std::string name)
{
}
void Args::InputSystem::BindFunctionToAction(Args::Key key, std::function<void()> func)
{
	actionMap[key] = func;
}

void Args::InputSystem::BindFunctionToAxis(std::string name, std::function<void()> func)
{
}

void Args::InputSystem::BindFunctionToButtonEvent(std::string name, std::function<void()> func)
{
}


void Args::InputSystem::MapEventToKeyAction(std::string name, Key key)
{
	//events[name] = key;
}

void Args::InputSystem::MapEventToKeyAxis(std::string name, Key key, float value)
{

}

void Args::InputSystem::doSomething()
{
	Debug::Log(DebugInfo, "DidSomething");
}


