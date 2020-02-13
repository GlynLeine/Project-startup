#pragma once
#include <Args-Core.h>
#include <array>
#include <Bullet/btBulletCollisionCommon.h>
#include <Args-Math.h>

namespace Args
{
	struct BoxCollider : public Component<BoxCollider> , public btBoxShape
	{
		BoxCollider(uint32 entityId) : Component<BoxCollider>(entityId), btBoxShape(btVector3(0,0,0))
		{

		}

		bool isTrigger;
		Args::Vec3 center;
		Args::Vec3 size;

		// Inherited via Component
		virtual std::string ObjectType() override
		{
			return GetTypeName<BoxCollider>();
		}

		virtual bool SetData(const std::string& name, const std::string& value) override
		{
			if (name.find("isTrigger") != std::string::npos)
			{
				isTrigger = std::stoi(value);
				return true;
			}
			if (name.find("center") != std::string::npos)
			{
				size_t divider = 0;
				center.x = std::stof(value.substr(divider), &divider);
				center.y = std::stof(value.substr(divider), &divider);
				center.z = std::stof(value.substr(divider), &divider);
			}
			if (name.find("size") != std::string::npos)
			{
				size_t divider = 0;
				size.x = std::stof(value.substr(divider), &divider);
				size.y = std::stof(value.substr(divider), &divider);
				size.z = std::stof(value.substr(divider), &divider);
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
