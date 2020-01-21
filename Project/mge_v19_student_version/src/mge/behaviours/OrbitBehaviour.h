#pragma once

#include "mge/core/GameObject.hpp"
#include "mge/behaviours/AbstractBehaviour.hpp"

class OrbitBehaviour : public AbstractBehaviour
{
public:
	OrbitBehaviour(GameObject* target, bool allowZoom = false, float dist = 1.f);
	OrbitBehaviour(GameObject* target, float dist = 1.f, bool allowZoom = false);

	virtual void update(float pStep);

	float orbitDistance;
	bool allowZoom;
private:
	GameObject* target;

	glm::vec3 prevTargetPos;
};