#pragma once
#include "ECS/System.h"
#include "Components/Collider.h"
#include "Base Components/Transform.h"

namespace Args
{
	class PickupSystem : public EntitySystem<PickupSystem, Collider, Transform>
	{
	public:
		PickupSystem() : EntitySystem<PickupSystem, Collider, Transform>() {}

		virtual void Init() override;
		void Update(float deltaTime);
		void OnTriggerStay(const Collision& collision);
		void OnTriggerExit(const Collision& collision);
	};
}