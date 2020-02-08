#include <cstdio>
#include <utility>
#include <Vector>
#include <Args.h>
#include "TestSystem.h"
#include <unordered_map>
#include <memory>
#include <type_traits>
#include <typeindex>
//
//struct BaseComponentA {
//	int value;
//	BaseComponentA(int v) : value(v) {};
//};
//struct TestComponentA : BaseComponentA {
//	bool a;
//	TestComponentA(int v, bool a) : BaseComponentA(v), a(a) {};
//};
//struct TestComponentB : BaseComponentA {
//	float b;
//	TestComponentB(int v, float b) : BaseComponentA(v), b(b) {};
//};
//struct TestComponentC : BaseComponentA {
//	char c;
//	TestComponentC(int v, char c) : BaseComponentA(v), c(c) {};
//};
//
//
//auto componentMap = std::unordered_map<unsigned, std::unordered_map<std::type_index, std::shared_ptr<BaseComponentA>>>();
//
//template<typename ComponentType, typename ...Components>
//void TestGetComponents(unsigned entityID, std::shared_ptr<ComponentType>& component, std::shared_ptr<Components>&... components)
//{
//	static_assert(std::is_base_of_v<BaseComponentA, ComponentType>, "One of the passed components doesn't inherit from Component.");
//	component = std::static_pointer_cast<ComponentType>(componentMap[entityID][typeid(ComponentType)]);
//
//	TestGetComponents(entityID, components...);
//
//	std::printf("%s \n", typeid(ComponentType).name());
//}
//
//void TestGetComponents(unsigned entityID)
//{
//}

//class TestThing
//{
//public:
//	static int value;
//
//	static  int SetValue()
//	{
//		std::cout << "set value" << std::endl;
//		return 0;
//	}
//};
//
//int TestThing::value = TestThing::SetValue();


int main()
{
	//componentMap[0] = std::unordered_map<std::type_index, std::shared_ptr<BaseComponentA>>();
	//componentMap[0][typeid(TestComponentA)] = std::make_shared<TestComponentA>(0, false);
	//componentMap[0][typeid(TestComponentB)] = std::make_shared<TestComponentB>(1, 0.13);
	//componentMap[0][typeid(TestComponentC)] = std::make_shared<TestComponentC>(2, 'G');

	//std::shared_ptr<TestComponentA> testPtrA = std::make_shared<TestComponentA>(4, true);
	//std::shared_ptr<TestComponentB> testPtrB;
	//std::shared_ptr<TestComponentC> testPtrC;

	//std::printf("%i %s \n", testPtrA->value, testPtrA->a ? "true" : "false");

	//TestGetComponents<TestComponentA, TestComponentB, TestComponentC>(0, testPtrA, testPtrB, testPtrC);

	//std::printf("%i %s \n", testPtrA->value, testPtrA->a ? "true" : "false");
	//std::printf("%i %f \n", testPtrB->value, testPtrB->b);
	//std::printf("%i %c \n", testPtrC->value, testPtrC->c);

	ECSManager manager;

	std::printf((std::string("../Logs/output") + Debug::GetDateTime() + std::string(".log")).c_str());

	for (int i = 0; i < 255; i++)
	{
		Debug::Log(i, DebugInfo, "color mode: %i", i);
	}

	std::printf("\n\n\n");

	Debug::ResetColor(SUCCESS);

	Debug::Error(DebugInfo, "Some error");
	Debug::Success(DebugInfo, "Some success");
	Debug::Warning(DebugInfo, "Some warning");

	manager.RegisterSystem<TestSystem>();
	manager.RegisterComponentType<TestComponent>();

	uint32 entity = manager.CreateEntity();
	manager.AddComponent<TestComponent>(entity);
	manager.AddComponent<TestComponent>(entity);
	manager.InitialiseSystems();
	Debug::CloseOutputFile();
	manager.UpdateSystems();
	manager.UpdateSystems();
	manager.UpdateSystems();
	manager.UpdateSystems();
	manager.UpdateSystems();

	Debug::CloseOutputFile();
	system("pause");
}


//std::vector<uint8> memory = std::vector<uint8>();
//int index = memory.size();
//memory.resize(index + sizeof(Args::ECSManager));
//manager = new(&memory[index]) Args::ECSManager();
