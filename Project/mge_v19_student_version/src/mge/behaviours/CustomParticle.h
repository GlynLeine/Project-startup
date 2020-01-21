#pragma once

#include "mge/behaviours/AbstractBehaviour.hpp"
#include "glm.hpp"

/**
 * Simply rotates the object around its origin with a fixed speed.
 */
class CustomParticle : public AbstractBehaviour
{
	public:
		CustomParticle(glm::vec3 min, glm::vec3 max, float speed, glm::vec3 direction);
		virtual ~CustomParticle();

		virtual void update(float pStep);
protected:
	int id;
	float time;
	glm::vec3 min;
	glm::vec3 max;
	float speed;
	glm::vec3 direction;
};