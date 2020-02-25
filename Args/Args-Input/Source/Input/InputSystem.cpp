#include "Input/InputSystem.h"

using namespace rapidjson;

void Args::InputSystem::Start()
{
	//mdcclxxvi
}

void Args::InputSystem::Init()
{
	BindForUpdate(std::bind(&InputSystem::Update, this, std::placeholders::_1));
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

		//assert(pair[0].IsString());
		//Debug::Log(DebugInfo, "Checking if second in Pair is a int");
		assert(pair[1].IsInt());
		//Debug::Log(DebugInfo, "True");

		buttonMap[pair[0].GetString()] = (Key)pair[1].GetInt();
		//Debug::Log(DebugInfo, "i%", buttonMap[pair[0].GetString()]);
	}

	Debug::Success(DebugInfo, "Initialised InputSystem");

	//std::function<void(bool, ControllerID)> func = std::bind(&Args::InputSystem::KeyActionDelegate, this, std::placeholders::_1, std::placeholders::_2);
	////std::function<void(bool, ControllerID)> func2 = std::bind(&Args::InputSystem::TestFunc, this, std::placeholders::_1, std::placeholders::_2);
	//BindFunctionToAction(ENTER, func);
}

void Args::InputSystem::Update(float deltaTime)
{
}

void Args::InputSystem::InvokeInputAction(Key key, bool pressed, ControllerID controllerID)
{
	//IF specified controller
	//actionMap[key](pressed,controllerID);
}
void Args::InputSystem::BindFunctionToAction(Args::Key key, std::function<void(bool, ControllerID)> func)
{
	//actionMap[key] = func;
}

void Args::InputSystem::BindFunctionToAxis(std::string name, std::function<void(float, std::list<ControllerID>)> func)
{
}

void Args::InputSystem::BindFunctionToButtonEvent(std::string name, std::function<void(Key, bool, ControllerID)> func)
{
}


void Args::InputSystem::MapEventToKeyAction(std::string name, Key key)
{
	//events[name] = key;
}

void Args::InputSystem::MapEventToKeyAxis(std::string name, Key key, float value)
{

}


