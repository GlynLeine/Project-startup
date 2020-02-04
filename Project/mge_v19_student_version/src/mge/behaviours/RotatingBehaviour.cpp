#include "mge/behaviours/RotatingBehaviour.hpp"
#include "mge/core/GameObject.hpp"

RotatingBehaviour::RotatingBehaviour(float rotationSpeed, glm::vec3 axis) : AbstractBehaviour(), rotationSpeed(rotationSpeed)
{
	this->axis = glm::normalize(axis);
}

RotatingBehaviour::~RotatingBehaviour()
{
	//dtor
}

void RotatingBehaviour::update(float pStep)
{
    //rotates 45° per second
	_owner->rotateLocal(pStep * glm::radians(45.0f * rotationSpeed), axis);
}
