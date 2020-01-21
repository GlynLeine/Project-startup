#include "mge/lights/SpotLight.h"
#include "mge/core/World.hpp"

SpotLight::SpotLight(const std::string& pName, const glm::vec3& pPosition) : Light(pName, pPosition)
{
	type = LightType::SPOT;
}

SpotLight::~SpotLight() {
}

LightData SpotLight::getLightData()
{
	position = glm::vec4(getWorldPosition(), 0);
	direction = getWorldTransform() * glm::vec4(0, 0, 1, 0);
	return lightData;
}

void SpotLight::SetAngle(float angle)
{
	this->angle = angle;
}

void SpotLight::SetFalloffPower(float power)
{
	falloff = power;
}


