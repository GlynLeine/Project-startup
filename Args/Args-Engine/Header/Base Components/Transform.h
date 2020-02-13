#pragma once
#include<ECS/Component.h>
#include <array>
#include <Args-Math.h>

namespace Args
{
	struct Transform : public Component<Transform>
	{
		Transform(uint32 entityId) : Component<Transform>(entityId) 
		{

		}

		Args::Vec3 position;
		Args::Vec4 rotation;
		Args::Vec3 scale;

		Args::Transform* children[20];

		Args::Vec3 forward;
		Args::Vec3 right;
		Args::Vec3 up;


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