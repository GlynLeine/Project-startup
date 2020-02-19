#include "Systems\TestSystem.h"
#include "Components\TestGlobalComponent.h"

using namespace Args;

void TestSystem::Init()
{
	BindForUpdate(std::bind(&TestSystem::Update, this, std::placeholders::_1));
	BindForFixedUpdate(0.5f, std::bind(&TestSystem::Print, this, std::placeholders::_1));
	BindForFixedUpdate(30.f, std::bind(&TestSystem::Shutdown, this, std::placeholders::_1));

	testInt = 0;
	elapsedTime = 0;
	Debug::Success(DebugInfo, "Initialised TestSystem");
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

	updatesSincePrint++;
	testInt++;
	elapsedTime += deltaTime;
	accumDeltaTime += deltaTime;
}

void TestSystem::Print(float deltaTime)
{
	if (updatesSincePrint == 0)
		Debug::Log(DEBUG_PURPLE, DebugInfo, "average delta time: more than 0.5 seconds\n");
	else
	{
		Debug::Log(DEBUG_PURPLE, DebugInfo, "average delta time: %fms\n", accumDeltaTime / updatesSincePrint);
		updatesSincePrint = 0;
		accumDeltaTime = 0;
	}
 
	TestComponent* testComponentA;
	TestComponent* testComponentB;

	GetComponents(&testComponentA, &testComponentB);
	TestGlobalComponent* testComponent = GetStaticComponent<TestGlobalComponent>();

	Debug::Log(DebugInfo, "Update call %i", testInt);
	Debug::Log(DebugInfo, "testComponentA: %f", testComponentA->value);
	Debug::Log(DebugInfo, "testComponentB: %f", testComponentB->value);
	Debug::Log(DebugInfo, "TestStaticComponent: %f\n", testComponent->value);
}

void TestSystem::Shutdown(float deltaTime)
{
	Debug::Success(DebugInfo, "Elapsed Time: %f", elapsedTime);
	Engine::RaiseEvent<Events::Exit>();
}
