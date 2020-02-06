#pragma once
#include <Args.h>

using namespace std;
using namespace Args;

class TestSystem : public Args::System<TestSystem, TestComponent, TestComponent>
{
private:
	int testInt;

	TestComponent* testComponentA;
	TestComponent* testComponentB;

public:
	TestSystem() : Args::System<TestSystem, TestComponent, TestComponent>(this)
	{

	}

	virtual void Init() override;

	void Start();

	void Update(float deltaTime);
};
