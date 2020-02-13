#pragma once
#include<ECS/Component.h>
#include <array>
#include <Args-Math.h>

namespace Args
{
	struct Rigidbody: public Component<Rigidbody>
	{
		Rigidbody(uint32 entityId) : Component<Rigidbody>(entityId)
		{

		}

		float mass;
		float drag;
		float angularDrag;
		bool useGravity;
		bool isKinematic;
		bool freezeXPos = false;
		bool freezeYPos = false;
		bool freezeZPos = false;
		bool freezeXRot = false;
		bool freezeYRot = false;
		bool freezeZRot = false;


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
