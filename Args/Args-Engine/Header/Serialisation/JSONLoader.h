#pragma once
#include <Args-Core.h>
#include <rapidjson/document.h>
using namespace rapidjson;
using namespace std;

namespace Args
{
	class JSONLoader
	{
	public:
		std::string filePath;
		JSONLoader();
		JSONLoader(std::string path);

		void LoadScene(std::string fileName);
		void LoadSetupSettings(std::string fileName);
		std::string LoadKeyMap(std::string fileName);
	};
}
