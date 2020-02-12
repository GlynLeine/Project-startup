#pragma once
#pragma once
#include <Args-Core.h>

using namespace std;
using namespace Args;

class JSONLoader : public Args::GlobalSystem<JSONLoader>
{
public:
	std::string path;
	JSONLoader() : Args::GlobalSystem<JSONLoader>() {}

	virtual void Init() override;
	void LoadScene(std::string fileName);
	void LoadSetupSettings(std::string fileName);
};
