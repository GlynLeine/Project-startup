#pragma once
#include <set>
#include <string>


namespace Args
{
	class ECS;
	class Module
	{
		ECS* ecs;
	public:
		Module(ECS* ecs);

		virtual void InitComponents(const std::set<std::string>& arguments) = 0;

		virtual void InitSystems(const std::set<std::string>& arguments) = 0;

	};
}