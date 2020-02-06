#include "Base Components/TestComponent.h"

std::string Args::TestComponent::ObjectType()
{
	return std::string();
}

bool Args::TestComponent::SetData(const std::string& name, const std::string& value)
{
	return false;
}

bool Args::TestComponent::GetData(const std::string& name, std::string& value)
{
	return false;
}
