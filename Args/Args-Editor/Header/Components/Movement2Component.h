#pragma once
#include <Args-Core.h>
namespace Args
{
	struct Movement2Component : public Component<Movement2Component>
	{
		float MoveSpeed;
		float RotateSpeed;
		float JumpSpeed;
		bool Grounded;
		float DistToGround;
		float angle;
		float translation;
		Movement2Component(Entity* entity) : Args::Component<Movement2Component>(entity) 
		{
			MoveSpeed = 10;
			RotateSpeed = 10;
			JumpSpeed = 10;
			Grounded = false;
			DistToGround = 1;
			angle = 1;
			translation = 1;
		};

		virtual std::string ObjectType() override;
		virtual bool SetData(const std::string& name, const std::string& value) override;
		virtual bool GetData(const std::string& name, std::string& value) override;
	};
}