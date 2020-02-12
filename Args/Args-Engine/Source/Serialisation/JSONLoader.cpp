#include "Serialisation/JSONLoader.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include <fstream>
#include <iostream>
#include <array>
#include <list>
#include <filesystem>

using namespace rapidjson;

void JSONLoader::Init()
{
	path = "../Args-Editor/Project Protos/Assets/JSON/";

	//fstream inFile;
	//std::string json;
	//std::string filename = "../Args-Editor/Json Scene Serializer/Assets/SampleScene.JSON";
	//inFile.open(filename);
	//if (!inFile) {
	//	Debug::Error(DebugInfo, "Unable to open file: %s", filename.c_str());
	//	return; //exit(1); // terminate with error
	//}
	//if (inFile.is_open())
	//{
	//	getline(inFile, json);
	//}
}

void JSONLoader::LoadScene(std::string fileName)
{
	fstream inFile;
	std::string json;
	inFile.open(path + "JSONScenes/" + fileName);
	if (!inFile)
	{
		Debug::Error(DebugInfo, "Unable to open file: %s", fileName.c_str());
		return;
	}
	if (inFile.is_open())
	{
		getline(inFile, json);
	}
	inFile.close();

	Document dom;
	dom.Parse(json.c_str());
	assert(dom["Scene"].IsArray());
	const Value& Scene = dom["Scene"].GetArray();
	int index = 0;
	while (index < Scene.MemberCount())
	{
		if (Scene[index][0].IsString())
		{
			if (Scene[index][0] == "name")
			{
				Debug::Log(DebugInfo,"Name: %s" ,dom["Scene"][index][0].GetString());
				//set name to proper object
			}
		}
		if (Scene[index][1].IsArray())
		{
			const Value& components = Scene[index][1];
			Debug::Log(DebugInfo,"\t Components");
			//create components
			for (int i = 0;i<components.MemberCount();i++)
			{
				Debug::Log(DebugInfo, "\t\t%s", components[i].GetString());
			}
		}
		index++;
	}
}


void JSONLoader::LoadSetupSettings(std::string fileName)
{
}

