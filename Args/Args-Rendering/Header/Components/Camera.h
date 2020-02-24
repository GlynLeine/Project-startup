#pragma once
#include <Args-Core.h>

namespace Args
{
	struct Camera : public Component<Camera>
	{
		Camera(uint32 entityId) : Component(entityId) {}

		Vector3 GetPosition();
		Matrix4 GetViewProjection();

		// Inherited via Component
		virtual std::string ObjectType() override;

		virtual bool SetData(const std::string& name, const std::string& value) override;

		virtual bool GetData(const std::string& name, std::string& value) override;

	};
}