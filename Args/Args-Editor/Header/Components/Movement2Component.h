#pragma once
#include "ECS/Component.h"

namespace Args
{
	struct Movement2Component : public Component<Movement2Component>
	{
		float MoveSpeed;
		float RotateSpeed;
		float JumpSpeed;
		bool Grounded;
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
