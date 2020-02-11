#include "Serialisation/SerialisationSystem.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include <fstream>
#include <iostream>
#include <array>
#include <list>

using namespace rapidjson;

void SerialisationSystem::Init()
{

	fstream inFile;
	std::string json;
	std::string filename = "../Args-Editor/Json Scene Serializer/Assets/SampleScene.JSON";
	inFile.open(filename);
	if (!inFile) {
		Debug::Error(DebugInfo, "Unable to open file: %s", filename.c_str());
		return; //exit(1); // terminate with error
	}
	if (inFile.is_open())
	{
		getline(inFile, json);
	}
	inFile.close();
	Debug::Log(DEBUG_PURPLE, DebugInfo, "Initialising SerialisationSystem");
	Document document;
	document.Parse(json.c_str());
	const Value& Scene = document["Scene"];
	assert(Scene.IsArray());
	for (SizeType i = 0; i < Scene.Size(); i++) // Uses SizeType instead of size_t
	{
		Debug::Log(DebugInfo,Scene[i]["name"].GetString());
		const Value& components = Scene[i]["components"];
		assert(components.IsArray());
		for (SizeType j = 0; j < components.Size();j++)
		{
			assert(components[i]["name"].IsString());
			//Debug::Log(DebugInfo, "Component:"components[i]["name"].GetString());
		}
		//Debug::Log(DebugInfo, Scene[i]["name"].GetString());
		
	}
}