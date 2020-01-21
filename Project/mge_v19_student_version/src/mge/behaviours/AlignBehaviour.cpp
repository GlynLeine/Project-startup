#include "mge/behaviours/AlignBehaviour.hpp"
#include "mge/core/GameObject.hpp"

AlignBehaviour::AlignBehaviour(GameObject* target) : AbstractBehaviour(), target(target)
{
	//ctor
}

AlignBehaviour::~AlignBehaviour()
{
	//dtor
}

void AlignBehaviour::update(float pStep)
{
	glm::vec3 fwd = target->getLocalRotation() * glm::vec3(0, 0, -1);
	fwd.y = 0;
	fwd = glm::normalize(fwd);
    //rotates 45° per second
	_owner->setLocalRotation(glm::inverse(glm::lookAt(glm::vec3(0), fwd, glm::vec3(0, 1, 0))));
}
