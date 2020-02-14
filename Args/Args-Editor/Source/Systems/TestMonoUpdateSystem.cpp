#include "Systems\TestMonoUpdateSystem.h"
#include "Components\TestGlobalComponent.h"

using namespace Args;

void TestMonoUpdateSystem::Init()
{
	BindForUpdate(std::bind(&TestMonoUpdateSystem::Update, this, std::placeholders::_1));
	testInt = 0;
	Debug::Log(DEBUG_PURPLE, DebugInfo, "Initialising TestMonoUpdateSystem");
}

void TestMonoUpdateSystem::Start()
{
	testInt = 0;
}

void TestMonoUpdateSystem::Update(float deltaTime)
{
	TestGlobalComponent* testComponent = GetStaticComponent<TestGlobalComponent>();

	testComponent->value++;

	testInt++;
	printTimer += deltaTime;
	while (printTimer >= 0.5f)
	{
		printTimer -= 0.5f;
		Debug::Log(DebugInfo, "Update call %i", testInt);
		Debug::Log(DebugInfo, "TestStaticComponent: %f\n", testComponent->value);
	}
}