#pragma once
#include <ECS/System.h>
#include <Components/Movement2Component.h>
#include <Base Components/Transform.h>
#include <functional>

namespace Args
{
	class Movement2System : public EntitySystem<Movement2System, Movement2Component,Transform>
	{
	public:
		Movement2System() : Args::EntitySystem<Movement2System, Movement2Component,Transform>() {}

		virtual void Init() override;

		void Start();

		void Update(float deltaTime);

		void Move(int controllerID, float speed);

		void Rotate(int controllerID,float angleStep);

		void Print(float deltaTime);
	};
}