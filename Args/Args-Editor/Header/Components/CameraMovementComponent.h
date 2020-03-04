#pragma once
#include "Args-Math.h"
#include "ECS/Component.h"

namespace Args
{
	struct CameraMovementComponent : public Component<CameraMovementComponent>
	{
		Vec3 Player1;
		Vec3 Player2;
		float Height;
		// Inherited via Component
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
