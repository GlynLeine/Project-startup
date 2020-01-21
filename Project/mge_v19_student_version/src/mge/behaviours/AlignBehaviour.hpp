#pragma once

#include "mge/behaviours/AbstractBehaviour.hpp"

/**
 * Simply rotates the object around its origin with a fixed speed.
 */
class AlignBehaviour : public AbstractBehaviour
{
	public:
		AlignBehaviour(GameObject* target);
		virtual ~AlignBehaviour();

		virtual void update(float pStep);
protected:
	GameObject* target;
};