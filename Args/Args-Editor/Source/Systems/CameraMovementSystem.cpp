#include "Systems/CameraMovementSystem.h"

void CameraMovementSystem::Init()
{
	GetGlobalComponent<Args::Input>()->BindAxis("MoveX", std::bind(&CameraMovementSystem::MoveX, this, std::placeholders::_1, std::placeholders::_2));
	GetGlobalComponent<Args::Input>()->BindAxis("MoveY", std::bind(&CameraMovementSystem::MoveY, this, std::placeholders::_1, std::placeholders::_2));

	GetGlobalComponent<Args::Input>()->BindAxis("MoveDown", std::bind(&CameraMovementSystem::MoveDown, this, std::placeholders::_1, std::placeholders::_2));
	GetGlobalComponent<Args::Input>()->BindAxis("MoveUp", std::bind(&CameraMovementSystem::MoveUp, this, std::placeholders::_1, std::placeholders::_2));

	GetGlobalComponent<Args::Input>()->BindAxis("RotateX", std::bind(&CameraMovementSystem::RotateX, this, std::placeholders::_1, std::placeholders::_2));
	GetGlobalComponent<Args::Input>()->BindAxis("RotateY", std::bind(&CameraMovementSystem::RotateY, this, std::placeholders::_1, std::placeholders::_2));

	Args::Debug::Success(DebugInfo, "Initialised CameraMovementSystem");
}

void CameraMovementSystem::MoveX(Args::ControllerID controller, Args::AxisValue value)
{
	auto entities = GetEntityList();

	for (auto entity : entities)
	{
		Args::Transform* transform = GetComponent<Args::Transform>(entity);

		Args::Vector3 right = transform->GetRight();
		right.y = 0;

		transform->Move(Args::normalize(right) * value * 0.1f);
	}
}

void CameraMovementSystem::MoveY(Args::ControllerID controller, Args::AxisValue value)
{
	auto entities = GetEntityList();

	for (auto entity : entities)
	{
		Args::Transform* transform = GetComponent<Args::Transform>(entity);

		Args::Vector3 fwd = transform->GetForward();
		fwd.y = 0;

		transform->Move(Args::normalize(fwd) * value * -0.1f);
	}
}

void CameraMovementSystem::MoveDown(Args::ControllerID controller, Args::AxisValue value)
{
	value = (value + 1.f) * 0.5f;

	auto entities = GetEntityList();

	for (auto entity : entities)
	{
		Args::Transform* transform = GetComponent<Args::Transform>(entity);

		transform->Move(Args::up * value * -0.1f);
	}
}

void CameraMovementSystem::MoveUp(Args::ControllerID controller, Args::AxisValue value)
{
	value = (value + 1.f) * 0.5f;

	auto entities = GetEntityList();

	for (auto entity : entities)
	{
		Args::Transform* transform = GetComponent<Args::Transform>(entity);

		transform->Move(Args::up * value * 0.1f);
	}
}

void CameraMovementSystem::RotateX(Args::ControllerID controller, Args::AxisValue value)
{
	auto entities = GetEntityList();

	for (auto entity : entities)
	{
		Args::Transform* transform = GetComponent<Args::Transform>(entity);
		Args::Vector3 fwd = transform->GetForward();
		fwd = Args::rotate(fwd, -value * 0.05f, Args::up);

		transform->SetRotation((Args::Matrix3)Args::inverse(Args::lookAtLH(Args::zero, fwd, Args::up)));
	}
}

void CameraMovementSystem::RotateY(Args::ControllerID controller, Args::AxisValue value)
{
	auto entities = GetEntityList();

	for (auto entity : entities)
	{
		Args::Transform* transform = GetComponent<Args::Transform>(entity);
		Args::Vector3 fwd = transform->GetForward();
		fwd = Args::rotate(fwd, value * 0.05f, transform->GetRight());

		transform->SetRotation((Args::Matrix3)Args::inverse(Args::lookAtLH(Args::zero, fwd, Args::up)));
	}
}
