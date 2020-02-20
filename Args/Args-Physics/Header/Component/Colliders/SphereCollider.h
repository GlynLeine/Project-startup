#pragma once
#include<ECS/Component.h>
#include <array>
#include <Args-Math.h>
#include <Bullet/btBulletCollisionCommon.h>

namespace Args
{
	struct SphereCollider: public Component<SphereCollider>, public btSphereShape
	{
		SphereCollider(uint32 entityId) : Component<SphereCollider>(entityId), btSphereShape(0)
		{

		}

		bool isTrigger;
		Args::Vec3 center;
		float radius;

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