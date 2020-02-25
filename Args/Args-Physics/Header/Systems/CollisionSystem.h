#pragma once
#include <Args-Core.h>
#include "Helpers/CollisionAlgorithm.h"
#include <vector>


namespace Args
{
	class CollisionSystem : public Args::MonoUpdateSystem<CollisionSystem>
	{
		public:
			std::unordered_map<int, std::unordered_map<int, CollisionAlgorithm*>> lookUpAlgorithm;
			CollisionSystem();
			~CollisionSystem();
		private:
			std::vector<Component<Collider>> colliders;
			void updateColliders();
			
	};
}
