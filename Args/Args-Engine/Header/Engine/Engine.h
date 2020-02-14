#pragma once
#include <vector>
#include <memory>
#include <set>
#include "Utils/Common.h"
#include "Module.h"
#include "ECS/Managers/ECS.h"
#include "Events/Event.h"

namespace Args
{
	class Engine
	{
	private:
		std::vector<std::unique_ptr<Module>> modules;
		ECS ecs;

		std::set<std::string> commandlineArguments;
		static std::set<uint32> events;
	public:

		Engine(int argc, char* argv[]);
		Engine();
		~Engine();

		void Initialise();

		template<typename EventType, INHERITS_FROM(EventType, IEvent)>
		static void RaiseEvent();

		template<typename EventType, INHERITS_FROM(EventType, IEvent)>
		static bool CheckEvent();

		template<typename ModuleType, INHERITS_FROM(ModuleType, Module)>
		void ReportModule();

		void Run();

		template<class ComponentType, INHERITS_FROM(ComponentType, IComponent)>
		uint32 AddComponent(uint32 entityId);

		uint32 CreateEntity()
		{
			return ecs.CreateEntity();
		}

		template<class SystemType, INHERITS_FROM(SystemType, ISystem)>
		void RegisterSystem(uint32 priority = 999);

		template<typename ComponentType, INHERITS_FROM(ComponentType, IGlobalComponent)>
		void RegisterStaticComponentType();

		template<typename ComponentType, INHERITS_FROM(ComponentType, IComponent)>
		void RegisterComponentType();
	};

	template<typename EventType, typename>
	inline void Engine::RaiseEvent()
	{
		events.insert(EventType::id);
	}

	template<typename EventType, typename>
	inline bool Engine::CheckEvent()
	{
		return events.count(EventType::id);
	}

	template<typename ModuleType, typename>
	inline void Engine::ReportModule()
	{
		modules.push_back(std::make_unique<ModuleType>());
	}

	template<typename ComponentType, typename>
	inline uint32 Engine::AddComponent(uint32 entityId)
	{
		return ecs.AddComponent<ComponentType>(entityId);
	}

	template<class SystemType, typename>
	inline void Engine::RegisterSystem(uint32 priority)
	{
		ecs.RegisterSystem<SystemType>(priority);
	}

	template<typename ComponentType, typename>
	inline void Engine::RegisterStaticComponentType()
	{
		ecs.RegisterStaticComponentType<ComponentType>();
	}

	template<typename ComponentType, typename>
	inline void Engine::RegisterComponentType()
	{
		ecs.RegisterComponentType<ComponentType>();
	}
}