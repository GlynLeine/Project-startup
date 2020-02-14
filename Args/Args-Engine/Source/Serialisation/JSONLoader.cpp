#include "Serialisation/JSONLoader.h"
#include "rapidjson/rapidjson.h"
#include "rapidjson/document.h"
#include <fstream>
#include <iostream>
#include <array>
#include <list>
#include <filesystem>

using namespace rapidjson;


Args::JSONLoader::JSONLoader()
{
	filePath = "../Args-Editor/Project Protos/Assets/JSON/";
}

Args::JSONLoader::JSONLoader(std::string path)
{
	filePath = path;
}

void Args::JSONLoader::LoadScene(std::string fileName)
{
	fstream inFile;
	std::string json;
	inFile.open(filePath + "JSONScenes/" + fileName);
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
	Debug::Log(DebugInfo, "Aserting...");
	assert(dom["Scene"].IsArray());
	Debug::Log(DebugInfo, "...Done!");

	const Value& Scene = dom["Scene"].GetArray();
	SizeType index = 0;
	while (index < Scene.Size())
	{
		const Value& object = Scene[index];
		if (object["name"].IsString())
		{
			Debug::Log(DebugInfo, "Name: %s", object["name"].GetString());
			//set name to proper object
		}
		if (object["components"].IsArray())
		{
			const Value& components = object["components"];
			Debug::Log(DebugInfo, "\t Components");
			//create components
			for (SizeType i = 0; i < components.Size(); i++)
			{
				Debug::Log(DebugInfo, "\t\t%s", components[i]["name"].GetString());
				if (components[i]["name"].GetString() == "Transform")
				{
					//Create Transform
				}
				else if (components[i]["name"].GetString() == "Mesh")
				{
					//Create Mesh
				}
				else if (components[i]["name"].GetString() == "Rigidbody")
				{
					//Create Rigibody
				}
				else if (components[i]["name"].GetString() == "SphereCollider")
				{
					//Create SphereCollider
				}
				else if (components[i]["name"].GetString() == "BoxCollider")
				{
					//Create BoxCollider
				}
				else
				{
					//This will be used to create other known scripts
				}
			}
		}
		Debug::Log(DebugInfo, "Done...");
		//add object to scene
		index++;
	}
}


void Args::JSONLoader::LoadSetupSettings(std::string fileName)
{
}

void Args::JSONLoader::LoadKeyMap(std::string fileName/*,InputSystem inputSys*/)
{
	fstream inFile;
	std::string json;
	inFile.open(filePath + "JSONKeymap/" + fileName);
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
	assert(dom["Keys"].IsArray());
	const Value& keyPairs = dom["Keys"].GetArray();
	SizeType i = 0;
	for (i = 0;i<keyPairs.Size();i++)
	{
		assert(keyPairs[i]["Pair"].IsArray());
		const Value& pair = dom["Keys"][i]["Pair"].GetArray();
		//add pairs to keymap from inputsystem
	}
}

