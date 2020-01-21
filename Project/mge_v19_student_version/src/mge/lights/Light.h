#pragma once

#include "glm.hpp"
#include "mge/core/GameObject.hpp"

enum LightType
{
	AREA = 0,
	DIRECTIONAL = 1,
	SPOT = 2
};

struct LightData
{
	int lightType;
	float attenuation;
	float intensity;
	float angle;
	glm::vec4 direction;
	glm::vec4 position;
	glm::vec4 colour;
};

/**
 * Exercise for the student: implement the Light class...
 * Imagine things like setLightType, setLightIntensity, setFalloffAngle etc, see the corresponding lectures
 */
class Light : public GameObject
{
public:
	Light(const std::string& aName = nullptr, const glm::vec3& aPosition = glm::vec3(2.0f, 10.0f, 5.0f));
	virtual ~Light();

	//override set parent to register/deregister light...
	virtual void _setWorldRecursively(World* pWorld) override;

	virtual LightData getLightData() = 0;
	virtual void SetAttenuation(float attenuation);
	virtual void SetIntensity(float intensity);
	virtual void SetColour(glm::vec3 colour);

protected:
	union
	{
		LightData lightData;

		struct
		{
			int type;
			float attenuation;
			float intensity;
			float angle;
			glm::vec3 direction;
			float falloff;
			glm::vec4 position;
			glm::vec4 colour;
		};
	};
};