#pragma once
#include <Args-Core.h>
#include "TestComponent.h"

using namespace std;

class TestSystem : public Args::System<TestSystem, TestComponent, TestComponent>
{
private:
	int testInt = 0;

public:
	TestSystem() : Args::System<TestSystem, TestComponent, TestComponent>() {}

	virtual void Init() override;

	void Start();

	void Update(float deltaTime);
};
