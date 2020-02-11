#include "TestMonoUpdateSystem.h"
#include "TestGlobalComponent.h"

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
	Debug::Log(DebugInfo, "Update call %i", testInt);
	Debug::Log(DebugInfo, "TestStaticComponent: %f\n", testComponent->value);
}
