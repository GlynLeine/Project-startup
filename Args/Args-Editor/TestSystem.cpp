#include "TestSystem.h"

void TestSystem::Init()
{
	BindForUpdate(std::bind(&TestSystem::Update, this, std::placeholders::_1));
	testInt = 0;
	Debug::Log(DebugInfo, "Init TestSystem");
}

void TestSystem::Start()
{
	testInt = 0;
}

void TestSystem::Update(float deltaTime)
{
	TestComponent* testComponentA;
	TestComponent* testComponentB;

	GetComponents(&testComponentA, &testComponentB);

	testComponentA->value += 0.1f;
	testComponentB->value += 0.5f;

	testInt++;
	Debug::Log(DebugInfo, "Update call %i", testInt);
	Debug::Log(DebugInfo, "testComponentA: %f", testComponentA->value);
	Debug::Log(DebugInfo, "testComponentB: %f", testComponentB->value);
}
