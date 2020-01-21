#pragma once

#include "glm.hpp"
#include "mge/core/GameObject.hpp"
#include "mge/lights/Light.h"


/**
 * Exercise for the student: implement the Light class...
 * Imagine things like setLightType, setLightIntensity, setFalloffAngle etc, see the corresponding lectures
 */
class SpotLight : public Light
{
public:
	SpotLight(const std::string& aName = nullptr, const glm::vec3& aPosition = glm::vec3(2.0f, 10.0f, 5.0f));
	virtual ~SpotLight();

	virtual LightData getLightData() override;
	void SetAngle(float angle);
	void SetFalloffPower(float power);
};
