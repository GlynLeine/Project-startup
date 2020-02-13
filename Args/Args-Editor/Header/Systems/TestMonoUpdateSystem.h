#pragma once
#include <Args-Core.h>

using namespace std;
using namespace Args;

class TestMonoUpdateSystem : public Args::GlobalSystem<TestMonoUpdateSystem>
{
private:
	int testInt = 0;
	float printTimer = 0;

public:
	TestMonoUpdateSystem() : Args::GlobalSystem<TestMonoUpdateSystem>() {}

	virtual void Init() override;

	void Start();

	void Update(float deltaTime);
};
