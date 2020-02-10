#pragma once
#pragma once
#include <Args-Core.h>

using namespace std;
using namespace Args;

class SerialisationSystem : public Args::StateLessSystem<SerialisationSystem>
{
public:
	SerialisationSystem() : Args::StateLessSystem<SerialisationSystem>(this) {}

	virtual void Init() override;
};
