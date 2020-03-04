#pragma once
#include <Args-Core.h>

namespace Args
{
	class MovementModule : public Args::Module
	{
	public:
		MovementModule(Args::ECS& ecs) : Args::Module(ecs) {}

		// Inherited via Module
		virtual void InitComponents(const std::set<std::string>& arguments) override;
		virtual void InitSystems(const std::set<std::string>& arguments) override;
	};
}