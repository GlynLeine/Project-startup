#include "Components/Camera.h"

Args::Vector3 Args::Camera::GetPosition()
{
	return Vector3();
}

Args::Matrix4 Args::Camera::GetViewProjection()
{
	return Matrix4();
}

std::string Args::Camera::ObjectType()
{
	return std::string();
}

bool Args::Camera::SetData(const std::string& name, const std::string& value)
{
	return false;
}

bool Args::Camera::GetData(const std::string& name, std::string& value)
{
	return false;
}
