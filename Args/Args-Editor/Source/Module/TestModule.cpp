#include "Module/TestModule.h"
#include "Components/TestComponent.h"
#include "Components/TestGlobalComponent.h"
#include "Systems/TestSystem.h"
#include "Systems/TestGlobalSystem.h"


void TestModule::InitComponents(const std::set<std::string>& arguments)
{
	RegisterComponentType<TestComponent>();
	RegisterGlobalComponentType<TestGlobalComponent>();
}

void TestModule::InitSystems(const std::set<std::string>& arguments)
{
	RegisterSystem<TestSystem>();
	RegisterSystem<TestGlobalSystem>();
}
