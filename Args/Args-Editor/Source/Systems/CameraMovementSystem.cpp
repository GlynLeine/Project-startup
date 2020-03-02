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

		transform->Move(transform->GetRight() * value * 0.1f);
	}
}

void CameraMovementSystem::MoveY(Args::ControllerID controller, Args::AxisValue value)
{
	auto entities = GetEntityList();

	for (auto entity : entities)
	{
		Args::Transform* transform = GetComponent<Args::Transform>(entity);

		transform->Move(transform->GetForward() * value * -0.1f);
	}
}

void CameraMovementSystem::MoveDown(Args::ControllerID controller, Args::AxisValue value)
{
	value = (value + 1) * 0.5;

	auto entities = GetEntityList();

	for (auto entity : entities)
	{
		Args::Transform* transform = GetComponent<Args::Transform>(entity);

		transform->Move(Args::up * value * -0.1f);
	}
}

void CameraMovementSystem::MoveUp(Args::ControllerID controller, Args::AxisValue value)
{
	value = (value + 1) * 0.5;

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

		transform->Rotate(Args::up, value * -0.01f);
	}
}

void CameraMovementSystem::RotateY(Args::ControllerID controller, Args::AxisValue value)
{
	auto entities = GetEntityList();

	for (auto entity : entities)
	{
		Args::Transform* transform = GetComponent<Args::Transform>(entity);

		transform->Rotate(transform->GetRight(), value * -0.01f);
	}
}
