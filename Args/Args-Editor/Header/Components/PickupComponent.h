#pragma once
#include <Args-Core.h>

namespace Args
{
	struct PickupComponent : public Component <PickupComponent>
	{
		bool PickingUp;
		float VertThrowPow;
		float HorThrowPow;
		uint32 PickedUpObject;

		PickupComponent(Entity* entity) : Args::Component<PickupComponent>(entity)
		{

		}

		virtual std::string ObjectType() override
		{
			return std::string();
		}

		virtual bool SetData(const std::string& name, const std::string& value) override
		{
			return false;
		}

		virtual bool GetData(const std::string& name, std::string& value) override
		{
			return false;
		}
	};
}