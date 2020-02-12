#pragma once
#include<ECS/Component.h>
#include <array>
#include <Args-Math.h>

namespace Args
{
	struct BoxCollider : public Component<BoxCollider>
	{

		BoxCollider();
		BoxCollider(uint32 entityId) : Component<BoxCollider>(entityId)
		{

		}
		bool isTrigger;
		Args::Vec3 center;
		Args::Vec3 size;
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
