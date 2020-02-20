#pragma once
#include <Args-Core.h>
#include "Components/TestComponent.h"

using namespace std;

class TestSystem : public Args::EntitySystem<TestSystem, TestComponent, TestComponent>
{
private:
	int testInt = 0;

public:
	TestSystem() : Args::EntitySystem<TestSystem, TestComponent, TestComponent>() {}

	virtual void Init() override;

	void Start();

	void Update(float deltaTime);

	void Print(float deltaTime);
};
