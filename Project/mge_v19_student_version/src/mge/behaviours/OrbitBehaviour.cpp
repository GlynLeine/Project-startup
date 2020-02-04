#include "OrbitBehaviour.h"
#include <SFML/Window.hpp>
#include <SFML/Window/Mouse.hpp>
#include "mge/core/AbstractGame.hpp"

OrbitBehaviour::OrbitBehaviour(GameObject* target, bool allowZoom, float dist) : target(target), orbitDistance(dist), allowZoom(allowZoom), prevTargetPos(glm::vec3(0))
{
}

OrbitBehaviour::OrbitBehaviour(GameObject* target, float dist, bool allowZoom) : target(target), orbitDistance(dist), allowZoom(allowZoom), prevTargetPos(glm::vec3(0))
{
}

void OrbitBehaviour::update(float pStep)
{
	if (!target)
		return;

	if (allowZoom)
	{
		orbitDistance -= 0.5f * AbstractGame::mouseWheelDir;
		if (orbitDistance <= 0.01f)
			orbitDistance = 0.01f;
	}

	auto delta = AbstractGame::mouseDelta;
	glm::vec3 targetPos = target->getWorldPosition();
	glm::vec3 direction = glm::normalize((_owner->getWorldPosition() - (prevTargetPos - targetPos)) - targetPos);
	float yAngle = glm::half_pi<float>() - glm::acos(glm::dot(direction, glm::vec3(0, 1, 0)));

	direction = glm::rotate((float)-delta.x, glm::vec3(0, 1, 0)) * glm::vec4(direction, 0);

	glm::vec3 right = glm::normalize(glm::cross(glm::vec3(0, 1, 0), direction));

	if (yAngle + delta.y > glm::radians(89.f))
		delta.y = glm::radians(89.f) - yAngle;

	if (yAngle + delta.y < glm::radians(-89.f))
		delta.y = glm::radians(-89.f) - yAngle;

	direction = glm::rotate((float)-delta.y, right) * glm::vec4(direction, 0);
	glm::vec3 localPos = glm::normalize(direction) * orbitDistance;

	localPos += targetPos;

	if (_owner->getParent())
		localPos = glm::inverse(_owner->getParent()->getWorldTransform()) * glm::vec4(localPos, 1);

	_owner->setLocalPosition(localPos);
	prevTargetPos = targetPos;
}
