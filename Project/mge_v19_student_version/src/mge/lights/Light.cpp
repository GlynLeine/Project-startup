#include "mge/lights/Light.h"
#include "mge/core/World.hpp"

Light::Light(const std::string& pName, const glm::vec3& pPosition) :GameObject(pName, pPosition)
{
	type = 0;
	attenuation = 10;
	direction = glm::vec3();
	position = glm::vec4();
	colour = glm::vec4(1, 1, 1, 1);
	intensity = 1;
	angle = glm::radians(180.f);
	falloff = glm::pi<float>();
}

Light::~Light() {
}

//Override setWorldRecursively to make sure we are registered
//to the world we are a part of.
void Light::_setWorldRecursively(World* pWorld) {

	//store the previous and new world before and after storing the given world
	World* previousWorld = _world;
	GameObject::_setWorldRecursively(pWorld);
	World* newWorld = _world;

	//check whether we need to register or unregister
	if (previousWorld != nullptr) previousWorld->unregisterLight(this);
	if (newWorld != nullptr) newWorld->registerLight(this);

}

void Light::SetAttenuation(float attenuation)
{
	this->attenuation = attenuation;
}

void Light::SetIntensity(float intensity)
{
	this->intensity = intensity;
}

void Light::SetColour(glm::vec3 colour)
{
	this->colour = glm::vec4(colour, 1);
}


