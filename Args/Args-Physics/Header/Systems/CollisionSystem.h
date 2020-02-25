#pragma once
#include <Args-Core.h>
#include "Helpers/CollisionAlgorithm.h"


namespace Args
{
	class CollisionSystem : public Args::MonoUpdateSystem<CollisionSystem>
	{
		public:
			std::unordered_map<int, std::unordered_map<int, CollisionAlgorithm*>> lookUpAlgorithm;
			CollisionSystem();
			~CollisionSystem();
		private:
			std::vector<Collider*> colliders;
			std::set<uint32> entities;
			void updateColliders();
			
	};
}
