#include "mge/lights/AreaLight.h"
#include "mge/core/World.hpp"

AreaLight::AreaLight(const std::string& pName, const glm::vec3& pPosition) : Light(pName, pPosition)
{
	type = LightType::AREA;
}

AreaLight::~AreaLight() {
}

LightData AreaLight::getLightData()
{
	position = glm::vec4(getWorldPosition(), 0);
	return lightData;
}


