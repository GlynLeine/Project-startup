#include "Components/Camera.h"

Args::Vector3 Args::Camera::GetPosition()
{
	return owner->GetComponent<Transform>()->Position();
}

Args::Matrix4 Args::Camera::GetViewProjection()
{
	return projection * inverse(owner->GetComponent<Transform>()->matrix);
}

std::string Args::Camera::ObjectType()
{
	return GetTypeName<Camera>();
}

bool Args::Camera::SetData(const std::string& name, const std::string& value)
{
	return false;
}

bool Args::Camera::GetData(const std::string& name, std::string& value)
{
	return false;
}
