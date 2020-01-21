#include "TargetBehaviour.h"
#include "mge/core/GameObject.hpp"

void TargetBehaviour::SetTarget(GameObject * gameObject)
{
	target = gameObject;
}

void TargetBehaviour::update(float pStep)
{
	if (!target)
		return;

	glm::vec3 eye = _owner->getWorldPosition();
	glm::vec3 center = target->getWorldPosition();

	if (eye.x == 0 && eye.y == 0 && eye.z == 0)
		eye = glm::vec3(0.000001, 0.000001, 0.000001);
	if (center.x == 0 && center.y == 0 && center.z == 0)
		center = glm::vec3(0.000001, 0.000001, 0.000001);

	auto transf = glm::inverse(glm::lookAt(eye, center, glm::vec3(0, 1, 0))) * glm::scale(_owner->getLocalScale());

	if (_owner->getParent())
		transf = glm::inverse(_owner->getParent()->getWorldTransform()) * transf;

	_owner->setTransform(transf);
}
