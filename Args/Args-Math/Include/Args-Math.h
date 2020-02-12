#pragma once
#define GLM_FORCE_RADIANS
#define GLM_ENABLE_EXPERIMENTAL

#include <GLM/glm.hpp>
#include <glm/ext.hpp>

namespace glm
{
	typedef glm::vec3 Vector3;
	typedef glm::vec3 Vec3;
	typedef glm::mat4 Matrix4;
	typedef glm::mat4 Mat4;
	typedef glm::vec2 Vector2;
	typedef glm::vec2 Vec2;
}

namespace Args
{
	inline namespace Math { using namespace ::glm; }
}


