#include "mge/lights/DirectionalLight.h"
#include "mge/core/World.hpp"

DirectionalLight::DirectionalLight(const std::string& pName, const glm::vec3& pPosition) : Light(pName, pPosition)
{
	type = LightType::DIRECTIONAL;
	attenuation = FLT_MAX;
}

DirectionalLight::~DirectionalLight() {
}

LightData DirectionalLight::getLightData()
{
	direction = getWorldTransform() * glm::vec4(0, 0, 1, 0);
	return lightData;
}

void DirectionalLight::SetAttenuation(float attenuation)
{
}
