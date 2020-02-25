#pragma once
#include <Args-Core.h>
#include <Args-Math.h>
#include <functional>

struct Collision;

namespace Args
{
	struct Collider : public Component<Collider>
	{
		Vec3 origin;
		enum colliderType {Box, Sphere};
		Vec3 size;
		std::vector<Collision> collisions;
		bool isTrigger;
		std::vector<std::function<void(Collision)>> OnCollisionCallback;
		std::vector<std::function<void(Collision)>> OnCollisionStayCallback;
		std::vector<std::function<void(Collision)>> OnCollisionEndCallback;

		Collider(uint32 entityId) : Component<Collider>(entityId)
		{
			
		}

		// Inherited via Component
		virtual std::string ObjectType() override
		{
			return GetTypeName<Collider>();
		}

		virtual bool SetData(const std::string& name, const std::string& value) override
		{
			if (name.find("isTrigger") != std::string::npos)
			{
				return true;
			}
			if (name.find("center") != std::string::npos)
			{
				return true;
			}
			if (name.find("size") != std::string::npos)
			{
				return true;
			}
			return false;
		}

		virtual bool GetData(const std::string& name, std::string& value) override
		{
			//TODO
			/*if (name.find("center") != std::string::npos)
			{
				value
			}*/
			return false;
		}
	};
}