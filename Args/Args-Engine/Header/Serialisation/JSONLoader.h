#pragma once
#include <Args-Core.h>

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
		void LoadKeyMap(std::string fileName);
	};
}
