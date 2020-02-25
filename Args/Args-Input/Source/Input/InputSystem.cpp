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
	dom.Parse(jsonLoader.LoadKeyMap("KeyMapTest").c_str());
	assert(dom["KeyMaps"].IsArray());
	const Value& keyPairs = dom["Keys"].GetArray();
	SizeType i = 0;
	for (i = 0; i < keyPairs.Size(); i++)
	{
		assert(keyPairs[i]["Pair"].IsArray());
		const Value& pair = dom["KeyMaps"][i]["Pair"].GetArray();
		assert(pair[0].IsArray());
		//assert(pair[0].IsString());
		assert(pair[1].IsInt());
		std::vector<std::string> strings;
		for (SizeType i = 0; i < pair[0].GetArray().Size(); i++) {
			const Value& c = pair[0].GetArray()[i];
			strings.push_back(c.GetString());
		}
		buttonMap[strings[0]] = (Key)pair[1].GetInt();
		Debug::Log(DebugInfo, "i%", buttonMap[strings[0]]);
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


