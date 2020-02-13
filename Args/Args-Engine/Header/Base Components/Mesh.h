#pragma once
#include<ECS/Component.h>
#include <array>
#include <Args-Math.h>

namespace Args
{
	struct Mesh : public Component<Mesh>
	{
		Mesh(uint32 entityId) : Component<Mesh>(entityId)
		{

		}

		std::string mesh;
		std::string material;
		bool castShadows;

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
