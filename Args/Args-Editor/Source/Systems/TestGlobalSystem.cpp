#include "Systems/TestGlobalSystem.h"
#include "Components/TestGlobalComponent.h"

using namespace Args;

void TestGlobalSystem::Init()
{
	BindForUpdate(std::bind(&TestGlobalSystem::Update, this, std::placeholders::_1));
	BindForFixedUpdate(0.5f, std::bind(&TestGlobalSystem::Print, this, std::placeholders::_1));
	BindForFixedUpdate(30.f, std::bind(&TestGlobalSystem::Shutdown, this, std::placeholders::_1));

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

	updatesSincePrint++;
	accumDeltaTime += deltaTime;
	elapsedTime += deltaTime;
}

void TestGlobalSystem::Print(float deltaTime)
{
	if (updatesSincePrint == 0)
		Debug::Log(DEBUG_PURPLE, DebugInfo, "average delta time: more than 0.5 seconds\n");
	else
	{
		Debug::Log(DEBUG_PURPLE, DebugInfo, "average delta time: %fs\n", accumDeltaTime / updatesSincePrint);
		updatesSincePrint = 0;
		accumDeltaTime = 0;
	}
}

void TestGlobalSystem::Shutdown(float deltaTime)
{
	Debug::Success(DebugInfo, "Elapsed Time: %f", elapsedTime);
	Engine::RaiseEvent<Events::Exit>();
}