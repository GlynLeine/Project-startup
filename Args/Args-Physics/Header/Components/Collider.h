#pragma once
#include <Args-Core.h>
#include <Args-Math.h>
#include <functional>

namespace Args
{
	struct Collision;

	struct Collider : public Component<Collider>
	{
		Vec3 origin;
		enum colliderTypes { Box, Sphere };
		int colliderType;
		Vec3 size;
		std::unordered_map<uint32, Collision> collisions;
		std::set<uint32> collidedWith;
		bool isTrigger;
		std::vector<std::function<void(const Collision&)>> OnCollisionCallback;
		std::vector<std::function<void(const Collision&)>> OnCollisionStayCallback;
		std::vector<std::function<void(const Collision&)>> OnCollisionEndCallback;

		Collider(Entity* entity) : Component<Collider>(entity)
		{
			size = Vector3(1);
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