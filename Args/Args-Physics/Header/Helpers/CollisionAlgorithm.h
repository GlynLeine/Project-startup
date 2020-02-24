#pragma once
#include "Collision.h"

namespace Args
{
	class CollisionAlgorithm
	{
		public:
			virtual Collision CollisionDetect(Collider _collider1, Collider _collider2);
	};
}
