#ifndef ROTATINGBEHAVIOUR_HPP
#define ROTATINGBEHAVIOUR_HPP

#include "mge/behaviours/AbstractBehaviour.hpp"
#include "glm.hpp"

/**
 * Simply rotates the object around its origin with a fixed speed.
 */
class RotatingBehaviour : public AbstractBehaviour
{
	public:
		RotatingBehaviour(float rotationSpeed = 1.f, glm::vec3 axis = glm::vec3(1.f));
		virtual ~RotatingBehaviour();

		virtual void update(float pStep);
protected:
	glm::vec3 axis;
	float rotationSpeed;
};

#endif // ROTATINGBEHAVIOUR_HPP
