#include "Systems\TestGlobalSystem.h"
#include "Components\TestGlobalComponent.h"

using namespace Args;

void TestGlobalSystem::Init()
{
	BindForUpdate(std::bind(&TestGlobalSystem::Update, this, std::placeholders::_1));
	testInt = 0;
	Debug::Log(DEBUG_PURPLE, DebugInfo, "Initialising TestMonoUpdateSystem");
}

void TestGlobalSystem::Start()
{
	testInt = 0;
}

void TestGlobalSystem::Update(float deltaTime)
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
