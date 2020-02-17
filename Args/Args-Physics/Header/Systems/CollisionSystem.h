#pragma once
#include <Args-Core.h>
#include <Bullet/btBulletCollisionCommon.h>
#include <vector>
#include <functional>
#include <Collision.h>

namespace Args
{
	class CollisionSystem : public Args::GlobalSystem<CollisionSystem>
	{
		public:
			void BindToCollisionEnter(std::function<void(Collision)>);
			void BindToCollisionStay(std::function<void(Collision)>);
			void BindToCollisionExit(std::function<void(Collision)>);
		private:
			std::vector<std::function<void(Collision)>> CollisionEnterCallBack;
			std::vector<std::function<void(Collision)>> CollisionStayCallBack;
			std::vector<std::function<void(Collision)>> CollisionExitCallBack;

	};
}