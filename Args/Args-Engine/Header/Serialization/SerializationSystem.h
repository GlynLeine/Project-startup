#pragma once
#pragma once
#include <Args.h>

using namespace std;
using namespace Args;

class SerializationSystem : public Args::System<SerializationSystem, TestComponent, TestComponent>
{
private:
	int testInt;
	TestComponent* testComponentA;
	TestComponent* testComponentB;
public:
	SerializationSystem() : Args::System<SerializationSystem, TestComponent, TestComponent>(this)
	{

	}

	virtual void Init() override;

	void Start();
};
