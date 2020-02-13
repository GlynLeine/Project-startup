#include "Components/Renderable.h"

std::string Args::Renderable::ObjectType()
{
	return std::string();
}

bool Args::Renderable::SetData(const std::string& name, const std::string& value)
{
	return false;
}

bool Args::Renderable::GetData(const std::string& name, std::string& value)
{
	return false;
}
