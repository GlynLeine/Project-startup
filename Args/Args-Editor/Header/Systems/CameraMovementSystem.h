#pragma once
#include <Args-Core.h>
#include <Args-Input.h>
#include <Args-Rendering.h>

class CameraMovementSystem : public Args::MonoUpdateSystem<CameraMovementSystem, Args::Camera, Args::Transform>
{
public:
	CameraMovementSystem() : Args::MonoUpdateSystem<CameraMovementSystem, Args::Camera, Args::Transform>() {}

	// Inherited via MonoUpdateSystem
	virtual void Init() override;


	void MoveX(Args::ControllerID controller, Args::AxisValue value);
	void MoveY(Args::ControllerID controller, Args::AxisValue value);

	void RotateX(Args::ControllerID controller, Args::AxisValue value);
	void RotateY(Args::ControllerID controller, Args::AxisValue value);
};