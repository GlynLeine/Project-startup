#include "Base Components/Transform.h"
#include "ECS/Managers/ComponentManager.h"
#include "ECS/Entity.h"

Args::Vector3 Args::Transform::GetPosition() const
{
	return position;
}

void Args::Transform::SetPosition(const Vector3& position)
{
	this->position = position;
}

Args::Vector3 Args::Transform::GetScale() const
{
	return Vector3(length(scaledRotationX), length(scaledRotationY), length(scaledRotationZ));
}

void Args::Transform::SetScale(const Vector3& scale)
{
	scaledRotationX = normalize(scaledRotationX) * scale.x;
	scaledRotationY = normalize(scaledRotationY) * scale.y;
	scaledRotationZ = normalize(scaledRotationZ) * scale.z;
}

Args::Quaternion Args::Transform::GetRotation() const
{
	return quat_cast(Matrix3(normalize(scaledRotationX), normalize(scaledRotationY), normalize(scaledRotationZ)));
}

void Args::Transform::SetRotation(const Quaternion& rotation)
{
	Vector3 scale = GetScale();
	Matrix3 mat = mat3_cast(rotation);

	scaledRotationX = mat[0] * scale.x;
	scaledRotationY = mat[0] * scale.y;
	scaledRotationZ = mat[0] * scale.z;
}

Args::Vector3 Args::Transform::RotatePoint(const Vector3& point)
{
	return matrix * Vector4(point, 0);
}

Args::Vector3 Args::Transform::TransformPoint(const Vector3& point)
{
	return matrix * Vector4(point, 1);
}

Args::Vector3 Args::Transform::GetForward()
{
	return RotatePoint(forward);
}

Args::Vector3 Args::Transform::GetRight()
{
	return RotatePoint(right);
}

Args::Vector3 Args::Transform::GetUp()
{
	return RotatePoint(up);
}

void Args::Transform::Rotate(const Vector3& axis, float angle)
{
	Quaternion rotation = GetRotation();

	rotate(rotation, angle, axis);

	SetRotation(rotation);
}

void Args::Transform::Move(const Vector3& translation)
{
	position += translation;
}

void Args::Transform::Scale(const Vector3& scale)
{
	SetScale(GetScale() * scale);
}

Args::Matrix4 Args::Transform::GetWorldTransform()
{
	if (parent == 0)
		return matrix;

	return manager->GetComponent<Transform>(parent)->GetWorldTransform() * matrix;
}

Args::Vector3 Args::Transform::GetWorldPosition()
{
	if (parent == 0)
		return position;

	return manager->GetComponent<Transform>(parent)->GetWorldTransform() * Vector4(position, 1);
}

void Args::Transform::SetWorldPosition(const Vector3& position)
{
	if (parent == 0)
	{
		SetPosition(position);
		return;
	}

	this->position = inverse(manager->GetComponent<Transform>(parent)->GetWorldTransform()) * Vector4(position, 1);
}

Args::Vector3 Args::Transform::GetWorldScale()
{
	if (parent == 0)
		return GetScale();

	Matrix3 worldRotationScale = GetWorldTransform();
	return Vector3(length(worldRotationScale[0]), length(worldRotationScale[1]), length(worldRotationScale[2]));
}

void Args::Transform::SetWorldScale(const Vector3& scale)
{
	if (parent == 0)
	{
		SetScale(scale);
		return;
	}

	Matrix3 parentWorldRotationScale = manager->GetComponent<Transform>(parent)->GetWorldTransform();
	Vector3 parentWorldScale = Vector3(length(parentWorldRotationScale[0]), length(parentWorldRotationScale[1]), length(parentWorldRotationScale[2]));
	SetScale(scale / parentWorldScale);
}

Args::Quaternion Args::Transform::GetWorldRotation()
{
	if (parent == 0)
		GetRotation();

	Matrix3 worldRotationScale = GetWorldTransform();
	return quat_cast(Matrix3(normalize(worldRotationScale[0]), normalize(worldRotationScale[1]), normalize(worldRotationScale[2])));
}

void Args::Transform::SetWorldRotation(const Quaternion& rotation)
{
	if (parent == 0)
	{
		SetRotation(rotation);
		return;
	}

	Matrix3 parentWorldRotationScale = manager->GetComponent<Transform>(parent)->GetWorldTransform();
	Quaternion parentWorldRotation = quat_cast(Matrix3(normalize(parentWorldRotationScale[0]), normalize(parentWorldRotationScale[1]), normalize(parentWorldRotationScale[2])));
	SetRotation(inverse(parentWorldRotation) * rotation);
}

Args::Vector3 Args::Transform::WorldRotatePoint(const Vector3& point)
{
	return GetWorldTransform() * Vector4(point, 0);
}

Args::Vector3 Args::Transform::WorldTransformPoint(const Vector3& point)
{
	return GetWorldTransform() * Vector4(point, 1);
}

Args::Vector3 Args::Transform::GetWorldForward()
{
	return WorldRotatePoint(forward);
}

Args::Vector3 Args::Transform::GetWorldRight()
{
	return WorldRotatePoint(right);
}

Args::Vector3 Args::Transform::GetWorldUp()
{
	return WorldRotatePoint(up);
}

void Args::Transform::SetParent(Transform* transform)
{
	if (parent > 0)
		owner->manager->GetComponent<Transform>(parent)->RemoveChild(this);

	if (transform)
		transform->AddChild(this);
}

void Args::Transform::AddChild(Transform* transform)
{
	children.push_back(transform->ownerID);
	transform->parent = ownerID;
}

void Args::Transform::RemoveChild(Transform* transform)
{
	children.erase(std::remove(children.begin(), children.end(), transform->ownerID));
}
