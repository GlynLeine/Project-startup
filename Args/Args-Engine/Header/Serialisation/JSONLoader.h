#pragma once
#pragma once
#include <Args-Core.h>

using namespace std;
using namespace Args;

class JSONLoader
{
public:
	std::string path;
	JSONLoader();

	void LoadScene(std::string fileName);
	void LoadSetupSettings(std::string fileName);
	void LoadKeyMap(std::string fileName);
};
