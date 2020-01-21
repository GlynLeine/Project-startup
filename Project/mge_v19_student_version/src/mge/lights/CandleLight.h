#pragma once

#include "glm.hpp"
#include "mge/core/GameObject.hpp"
#include "mge/lights/AreaLight.h"


/**
 * Exercise for the student: implement the Light class...
 * Imagine things like setLightType, setLightIntensity, setFalloffAngle etc, see the corresponding lectures
 */
class CandleLight : public AreaLight
{
public:
	CandleLight(const std::string& aName = nullptr, const glm::vec3& aPosition = glm::vec3(2.0f, 10.0f, 5.0f));
	virtual ~CandleLight();

	virtual void SetColour(glm::vec3 colour) override;
};
