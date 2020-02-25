#pragma once
#include<ECS/Component.h>
#include <array>
#include <Args-Math.h>
#include <vector>

namespace Args
{
	struct Rigidbody : public Component<Rigidbody>
	{

		Vec3 velocity;
		std::vector<Vec3> forces;
		
		Rigidbody(uint32 entityId) : Component<Rigidbody>(entityId)
		{

		}

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