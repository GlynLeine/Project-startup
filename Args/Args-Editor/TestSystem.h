#pragma once
#include <Args-Core.h>

using namespace std;
using namespace Args;

class TestSystem : public Args::System<TestSystem, TestComponent, TestComponent>
{
private:
	int testInt = 0;

public:
	TestSystem() : Args::System<TestSystem, TestComponent, TestComponent>(this) {}

	virtual void Init() override;

	void Start();

	void Update(float deltaTime);
};
