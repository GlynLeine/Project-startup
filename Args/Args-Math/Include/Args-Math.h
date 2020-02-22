#pragma once
#define GLM_FORCE_RADIANS
#define GLM_ENABLE_EXPERIMENTAL

#include <GLM/glm.hpp>
#include <glm/ext.hpp>

namespace glm
{
	typedef glm::vec4 Vector4;
	typedef glm::vec4 Vec4;
	typedef glm::vec3 Vector3;
	typedef glm::vec3 Vec3;
	typedef glm::mat4 Matrix4;
	typedef glm::mat4 Mat4;
	typedef glm::vec2 Vector2;
	typedef glm::vec2 Vec2;
	typedef glm::ivec2 IVector2;
	typedef glm::ivec2 IVec2;
	typedef glm::ivec3 IVector3;
	typedef glm::ivec3 IVec3;
}

namespace Args
{
	inline namespace Math { using namespace ::glm; }
}


