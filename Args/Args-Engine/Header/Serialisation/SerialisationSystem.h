#pragma once
#pragma once
#include <Args-Core.h>

using namespace std;
using namespace Args;

class SerialisationSystem : public Args::GlobalSystem<SerialisationSystem>
{
public:
	SerialisationSystem() : Args::GlobalSystem<SerialisationSystem>() {}

	virtual void Init() override;
};
