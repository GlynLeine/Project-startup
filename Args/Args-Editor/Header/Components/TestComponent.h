#pragma once
#include<ECS/Component.h>


struct TestComponentA : public Args::Component<TestComponentA>
{
	TestComponentA(Args::uint32 entityId) : Args::Component<TestComponentA>(entityId) {}

	float value = 0;

	// Inherited via Component
	virtual std::string ObjectType() override
	{
		return Args::GetTypeName<TestComponentA>();
	}

	virtual bool SetData(const std::string& name, const std::string& value) override
	{
		return false;
	}

	virtual bool GetData(const std::string& name, std::string& value) override
	{
		return false;
	}
};

struct TestComponentB : public Args::Component<TestComponentB>
{
	TestComponentB(Args::uint32 entityId) : Args::Component<TestComponentB>(entityId) {}

	float value = 0;

	// Inherited via Component
	virtual std::string ObjectType() override
	{
		return Args::GetTypeName<TestComponentA>();
	}

	virtual bool SetData(const std::string& name, const std::string& value) override
	{
		return false;
	}

	virtual bool GetData(const std::string& name, std::string& value) override
	{
		return false;
	}
};
