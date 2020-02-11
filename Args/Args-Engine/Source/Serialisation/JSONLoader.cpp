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
	std::string path = "../Args-Editor/Json Scene Serializer/Assets";
	for (const auto& entry : std::filesystem::directory_iterator(path))
	{
		std::cout << entry.path() << std::endl;
	}

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