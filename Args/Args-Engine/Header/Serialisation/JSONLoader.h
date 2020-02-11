#pragma once
#pragma once
#include <Args-Core.h>

using namespace std;
using namespace Args;

class JSONLoader : public Args::GlobalSystem<JSONLoader>
{
public:
	JSONLoader() : Args::GlobalSystem<JSONLoader>() {}

	virtual void Init() override;
};
