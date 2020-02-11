#pragma once

namespace Args
{
	class ECS;
	class Module
	{
		ECS* ecs;

		Module(ECS* ecs);

		virtual void InitComponents() = 0;

		virtual void InitSystems() = 0;

	};
}