#include "TestSystem.h"
#include "TestGlobalComponent.h"

void TestSystem::Init()
{
	BindForUpdate(std::bind(&TestSystem::Update, this, std::placeholders::_1));
	testInt = 0;
	Debug::Log(DEBUG_PURPLE, DebugInfo, "Initialising TestSystem");
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

	TestGlobalComponent* testComponent = GetStaticComponent<TestGlobalComponent>();

	testComponent->value++;

	testInt++;
	Debug::Log(DEBUG_BLUE, DebugInfo, "Update call %i", testInt);
	Debug::Log(DEBUG_BLUE, DebugInfo, "testComponentA: %f", testComponentA->value);
	Debug::Log(DEBUG_BLUE, DebugInfo, "testComponentB: %f", testComponentB->value);
	Debug::Log(DEBUG_BLUE, DebugInfo, "TestStaticComponent: %f\n", testComponent->value);

}
