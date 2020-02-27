#pragma once
#include <Args-Math.h>

namespace Args
{
	struct LightData
	{
		int type;
		float attenuation;
		float intensity;
		Vector3 direction;
		float falloff;
		Vector3 position;
		float angle;
		Vector3 colour;
	};
}