#pragma once

#include "mge/behaviours/AbstractBehaviour.hpp"

class TargetBehaviour : public AbstractBehaviour
{
public:
	void SetTarget(GameObject* gameObject);

	virtual void update(float pStep);

private:

	GameObject* target;
};