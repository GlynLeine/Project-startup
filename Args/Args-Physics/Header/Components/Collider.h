#pragma once
#include <Args-Core.h>
#include <Args-Math.h>
#include <functional>
#include <glad/glad.h>
#include <Args-Rendering.h>

namespace Args
{
	struct Collision;

	enum class ColliderType { Box = 0, Sphere = 1 };

	struct Collider : public Component<Collider>
	{
		Vec3 origin;
		ColliderType colliderType;
		Vec3 size;
		std::unordered_map<uint32, Collision> collisions;
		std::set<uint32> collidedWith;
		bool isTrigger;
		bool debugRender;
		std::vector<std::function<void(const Collision&)>> OnCollisionCallback;
		std::vector<std::function<void(const Collision&)>> OnCollisionStayCallback;
		std::vector<std::function<void(const Collision&)>> OnCollisionEndCallback;

		Collider(Entity* entity) : Component<Collider>(entity), origin(0, 0, 0), size(1), colliderType(ColliderType::Box), isTrigger(false), debugRender(true) {}

		void DebugRender(Camera* camera, Transform* transform)
		{
			//demo of how to render some debug info using the good ol' direct rendering mode...
			glUseProgram(0);
			glMatrixMode(GL_PROJECTION);
			glLoadMatrixf(value_ptr(camera->projection));
			glMatrixMode(GL_MODELVIEW);
			glLoadMatrixf(value_ptr(camera->GetView() * transform->GetWorldTransform()));

			Vector3 center = transform->WorldTransformPoint(origin);
			Vector3 extends;
			if (colliderType == ColliderType::Sphere)
				extends = transform->WorldTransformPoint(origin + Vector3(size.x) * 0.5) - center;
			else
				extends = transform->WorldTransformPoint(origin + size * 0.5) - center;

			glBegin(GL_LINES);

			glColor3fv(value_ptr(Vector3(1, 0, 0)));
			glVertex3fv(value_ptr(center - Vector3(extends.x, 0, 0)));
			glVertex3fv(value_ptr(center + Vector3(extends.x, 0, 0)));

			glColor3fv(value_ptr(Vector3(0, 1, 0)));
			glVertex3fv(value_ptr(center - Vector3(0, extends.y, 0)));
			glVertex3fv(value_ptr(center + Vector3(0, extends.y, 0)));

			glColor3fv(value_ptr(Vector3(0, 0, 1)));
			glVertex3fv(value_ptr(center - Vector3(0, 0, extends.z)));
			glVertex3fv(value_ptr(center + Vector3(0, 0, extends.z)));

			glEnd();
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