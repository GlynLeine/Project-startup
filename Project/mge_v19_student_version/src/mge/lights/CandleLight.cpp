#include "mge/lights/CandleLight.h"
#include "mge/core/World.hpp"

CandleLight::CandleLight(const std::string& pName, const glm::vec3& pPosition) : AreaLight(pName, pPosition)
{

}

CandleLight::~CandleLight() {
}

void CandleLight::SetColour(glm::vec3 colour)
{
	this->colour = glm::vec4(colour, 0);
}


