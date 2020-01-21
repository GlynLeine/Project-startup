#include "mge/behaviours/RotatingBehaviour.hpp"
#include "mge/core/GameObject.hpp"

RotatingBehaviour::RotatingBehaviour(float rotationSpeed) : AbstractBehaviour(), rotationSpeed(rotationSpeed)
{
	//ctor
}

RotatingBehaviour::~RotatingBehaviour()
{
	//dtor
}

void RotatingBehaviour::update(float pStep)
{
    //rotates 45� per second
	_owner->rotateLocal(pStep * glm::radians(45.0f * rotationSpeed), glm::vec3( 1.0f, 1.0f, 0.0f ) );
}
