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
	//Engine::BindToEvent<Events::ControllerConnected>(std::bind(&InputSystem::OnControllerConnected,this,std::placeholders::_1));
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
		
		Key key;
		convert_string(pair[1].GetString(),key);
		enumStorage[pair[0].GetString()] = key;
		//Debug::Log(DebugInfo, "i%", buttonMap[pair[0].GetString()]);
	}
	Debug::Success(DebugInfo, "Initialised InputSystem");

}

void Args::InputSystem::Update(float deltaTime)
{
	//RESET AXES
	for (int i = 0; i < 6; i++)
	{
		axisMap[(Key)(1000 + i)] = 0;
	}

	//GET INPUT
	RetrieveInput();

	////BIND ACTIONS
	//std::function<void()> func = std::bind(&Args::InputSystem::doSomething, this);
	//for (int i = 0; i < 20; i++)
	//{
	//	BindFunctionToAction(glfwToKey[i], func);

	//}
	////BIND AXIS
	//std::function<void(float)> axisFunc = std::bind(&Args::InputSystem::axisDoSomething, this, std::placeholders::_1);
	//for (int i = 14; i < 20; i++)
	//{
	//	BindFunctionToAxis(glfwToKey[i], axisFunc);
	//}
	//INVOKE ACTION EVENTS.
	for (int i = 0; i < 14; i++)
	{
		if (i != 8)
		{
			InvokeAction(glfwToKey[i], true);
		}
	}
	//INVOKE AXIS EVENTS
	for (int i = 14; i < 20; i++)
	{
		InvokeAxis(glfwToKey[i]);
	}
}

void Args::InputSystem::RetrieveInput()
{
	releasedKeys.clear();
	pressedKeys.clear();
	for (int controller = 0; controller < 16; controller++)
	{
		if (glfwJoystickIsGamepad(controller))
		{
			if (!isConnected)
			{
				Debug::Log(DebugInfo, "The Joystick is Connected");
			}
			isConnected = true;

			GLFWgamepadstate state;
			if (glfwGetGamepadState(controller, &state) == GLFW_TRUE)
			{
				for (int i = 0; i < 15; i++)
				{
					if (state.buttons[i] == GLFW_PRESS && !keyPressed[i].count(controller))
					{
						Debug::Log(DebugInfo, "%i %u PressStarted", controller, i);
						keyPressed[i].insert(controller);
						pressedKeys[glfwToKey[i]].first = glfwToKey[i];
						pressedKeys[glfwToKey[i]].second.push_back(controller);
						continue;
					}
					if (state.buttons[i] == GLFW_RELEASE && keyPressed[i].count(controller))
					{
						Debug::Log(DebugInfo, "%i %u PressEnded", controller, i);
						keyPressed[i].erase(controller);
						releasedKeys[glfwToKey[i]].first = glfwToKey[i];
						releasedKeys[glfwToKey[i]].second.push_back(controller);
						continue;
					}
				}

				axisMap[JOYSTICK_LEFT_X] = state.axes[0];
				axisMap[JOYSTICK_LEFT_Y] = state.axes[1];
				axisMap[JOYSTICK_RIGHT_X] = state.axes[2];
				axisMap[JOYSTICK_RIGHT_Y] = state.axes[3];
				axisMap[BUMPER_L2] = state.axes[4];
				axisMap[BUMPER_R2] = state.axes[5];

				//for (int i = 0; i < 4; i++)//Analongs
				//{
				//	if (abs(state.axes[i]) > 0.000016f)
				//	{
				//		Debug::Log(DebugInfo, "Axis %i :%f", i, state.axes[i]);
				//	}
				//}
				//for (int i = 4; i < 6; i++)//Triggers
				//{
				//	if (state.axes[i] > -1.00000f)
				//	{
				//		Debug::Log(DebugInfo, "Triggers %i :%f", i, state.axes[i]);
				//	}
				//}
			}
		}
		//else 
		//{
		//	isConnected = false;
		//}
	}
}




void Args::InputSystem::BindFunction(std::string name, std::function<void()> func, bool onPress)
{
	BindFunctionToAction(enumStorage[name],func, onPress);
}
void Args::InputSystem::BindFunction(std::string name, std::function<void(float)> func)
{
	BindFunctionToAxis(enumStorage[name], func);
}
void Args::InputSystem::BindFunctionToAction(Args::Key key, std::function<void()> func, bool onPress)
{
	if (onPress)
	{
		if (pressedKeys[key].first == key)
		{
			actionMap[key] = func;
		}
	}
	else
	{
		if (releasedKeys[key].first == key)
		{
			actionMap[key] = func;
		}
	}
}
void Args::InputSystem::BindFunctionToAxis(Key key, std::function<void(float)> func)
{
	axisActionMap[key] = func;
}
void Args::InputSystem::InvokeAction(Key key, bool onPress)
{
	if (onPress)
	{
		if (pressedKeys[key].first == key)
		{
			actionMap[key]();
		}
	}
	else
	{
		if (releasedKeys[key].first == key)
		{
			actionMap[key]();
		}
	}
}
void Args::InputSystem::InvokeAxis(Key key)
{
	if (axisActionMap[key] != NULL)
	{
		if (key >= 1000 && key < 1004)
		{
			//Debug::Log(DebugInfo, "Checking Analogs");
			if (abs(axisMap[key]) > 0.00015f)
			{
				axisActionMap[key](axisMap[key]);
				//Debug::Log(DebugInfo, "Analog");
				return;
			}
		}
		else if (key >= 1004)
		{
			//Debug::Log(DebugInfo, "Checking Triggers");
			if (abs(axisMap[key]) < 1.0000f)
			{
				axisActionMap[key](axisMap[key]);
				//Debug::Log(DebugInfo, "Trigger");
				return;
			}
		}
	}
	//Debug::Log(DebugInfo, "DoSomething \n");
}
void Args::InputSystem::doSomething()
{
	Debug::Log(DebugInfo, "DidSomething");
}
void Args::InputSystem::axisDoSomething(float axis)
{
	Debug::Log(DebugInfo, "Axis: %f", axis);
}

//void Args::InputSystem::MapEventToKeyAction(std::string name, Key key)
//{
//
//}
//
//void Args::InputSystem::MapEventToKeyAxis(std::string name, Key key, float value)
//{
//
//
//void Args::InputSystem::UpdateAxesForKey(Key key, ControllerID controllerID)
//{
//}
//void Args::InputSystem::CreateEvent(std::string name)
//{
//}
//void Args::InputSystem::OnControllerConnected(IEvent& event)
//{
//	Events::ControllerConnected connectionEvent = reinterpret_cast<Events::ControllerConnected&>(event);
//	Debug::Log(DebugInfo, "Connected");
//}
//void Args::InputSystem::WhileControllerConnected(IEvent& event)
//{
//	Events::ControllerIsConnected connectionEvent = reinterpret_cast<Events::ControllerIsConnected&>(event);
//	Debug::Log(DebugInfo, "Still Connected");
//}
//void Args::InputSystem::OnControllerDisconnected(IEvent& event)
//{
//	Events::ControllerDisconnected connectionEvent = reinterpret_cast<Events::ControllerDisconnected&>(event);
//	Debug::Log(DebugInfo, "Disconnected");
//}






