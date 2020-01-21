#include "mge/behaviours/CustomParticle.h"
#include "mge/core/GameObject.hpp"

CustomParticle::CustomParticle(glm::vec3 min, glm::vec3 max, float speed, glm::vec3 direction) : AbstractBehaviour(), min(min), max(max), speed(speed), direction(direction), time(0.f)
{
	id = std::rand();
}

CustomParticle::~CustomParticle()
{
	//dtor
}

void CustomParticle::update(float pStep)
{
	time += pStep;

	glm::vec3 center = glm::vec3(min.x + (max.x - min.x)*0.5, min.y + (max.y - min.y)*0.5, min.z + (max.z - min.z)*0.5);
	glm::vec3 pos = _owner->getLocalPosition();

	float x = glm::simplex(glm::vec2(pos.y, pos.z) * 0.3f);
	float y = glm::simplex(glm::vec2(pos.x, pos.z) * 0.3f);
	float z = glm::simplex(glm::vec2(pos.x, pos.y) * 0.3f);

	direction += glm::vec3(x, y, z);

	glm::vec3 toCenter = center - pos;

	direction += toCenter * 0.05f;

	direction += glm::vec3(((float)(std::rand() % 2000) - 1000.f) / 1000.f, ((float)(std::rand() % 2000) - 1000.f) / 1000.f, ((float)(std::rand() % 2000) - 1000.f) / 1000.f);

	bool xOut = (min.x >= pos.x || max.x <= pos.x), yOut = (min.y >= pos.y || max.y <= pos.y), zOut = (min.z >= pos.z || max.z <= pos.z);

	if (xOut)
	{
		direction.x *= -1.1f;
	}

	if (yOut)
	{
		direction.y *= -1.1f;
	}

	if (zOut)
	{
		direction.z *= -1.1f;
	}

	pos += glm::normalize(direction) * speed * pStep;
	_owner->setLocalPosition(pos);

	float scale = (glm::simplex(glm::vec2(time * 0.2f + id)) * 0.0099f) + 0.0001f;
	_owner->setLocalScale(glm::vec3(scale));
}
