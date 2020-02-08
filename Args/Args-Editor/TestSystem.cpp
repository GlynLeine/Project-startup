#include "TestSystem.h"

void TestSystem::Init()
{
	BindForUpdate(&TestSystem::Update);
}

void TestSystem::Start()
{
	testInt = 0;
}

void TestSystem::Update(float deltaTime)
{
	GetComponents(testComponentA, testComponentB);

	testComponentA->value += 0.1f;
	testComponentB->value += 0.5f;

	testInt++;
	Debug::Log(DebugInfo, std::to_string(testInt));
	Debug::Log(DebugInfo, std::to_string(testComponentA->value));
	Debug::Log(DebugInfo, std::to_string(testComponentB->value));
}
