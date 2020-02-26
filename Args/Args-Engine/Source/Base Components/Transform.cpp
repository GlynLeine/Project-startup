#include "Base Components/Transform.h"
#include "ECS/Managers/ComponentManager.h"

Args::Vector3 Args::Transform::Position() const
{
	return position;
}

void Args::Transform::Position(const Vector3& position)
{
	this->position = position;
}

Args::Vector3 Args::Transform::Scale() const
{
	return Vector3(length(scaledRotationX), length(scaledRotationY), length(scaledRotationZ));
}

void Args::Transform::Scale(const Vector3& scale)
{
	scaledRotationX = normalize(scaledRotationX) * scale.x;
	scaledRotationY = normalize(scaledRotationY) * scale.y;
	scaledRotationZ = normalize(scaledRotationZ) * scale.z;
}

Args::Quaternion Args::Transform::Rotation() const
{
	return quat_cast(Matrix3(normalize(scaledRotationX), normalize(scaledRotationY), normalize(scaledRotationZ)));
}

void Args::Transform::Rotation(const Quaternion& rotation)
{
	Vector3 scale = Scale();
	Matrix3 mat = mat3_cast(rotation);

	scaledRotationX = mat[0] * scale.x;
	scaledRotationY = mat[0] * scale.y;
	scaledRotationZ = mat[0] * scale.z;
}

void Args::Transform::Rotate(const Vector3& axis, float angle)
{
	Quaternion rotation = Rotation();

	rotate(rotation, angle, axis);

	Rotation(rotation);
}

Args::Matrix4 Args::Transform::GetWorldTransform()
{
	if (parent == 0)
		return matrix;

	return manager->GetComponent<Transform>(parent)->GetWorldTransform() * matrix;
}
