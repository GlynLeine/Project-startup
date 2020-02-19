#include "Systems\TestGlobalSystem.h"
#include "Components\TestGlobalComponent.h"

using namespace Args;

void TestGlobalSystem::Init()
{
	BindForUpdate(std::bind(&TestGlobalSystem::Update, this, std::placeholders::_1));
	BindForFixedUpdate(0.5f, std::bind(&TestGlobalSystem::Print, this, std::placeholders::_1));
	testInt = 0;
	Debug::Success(DebugInfo, "Initialised TestMonoUpdateSystem");
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
}

void TestGlobalSystem::Print(float deltaTime)
{
	TestGlobalComponent* testComponent = GetStaticComponent<TestGlobalComponent>();

	Debug::Log(DebugInfo, "Update call %i", testInt);
	Debug::Log(DebugInfo, "TestStaticComponent: %f\n", testComponent->value);
}
