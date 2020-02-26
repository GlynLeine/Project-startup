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
	typedef glm::vec2 Vector2;
	typedef glm::vec2 Vec2;

	typedef glm::mat4 Matrix4;
	typedef glm::mat4 Mat4;
	typedef glm::mat3 Matrix3;
	typedef glm::mat3 Mat3;
	typedef glm::mat2 Matrix2;
	typedef glm::mat2 Mat2;

	typedef glm::ivec4 IVector4;
	typedef glm::ivec4 IVec4;
	typedef glm::ivec3 IVector3;
	typedef glm::ivec3 IVec3;
	typedef glm::ivec2 IVector2;
	typedef glm::ivec2 IVec2;

	typedef glm::bvec4 BVector4;
	typedef glm::bvec4 BVec4;
	typedef glm::bvec3 BVector3;
	typedef glm::bvec3 BVec3;
	typedef glm::bvec2 BVector2;
	typedef glm::bvec2 BVec2;

	typedef glm::quat Quaternion;
	typedef glm::quat Quat;
}

namespace Args
{
	inline namespace Math { using namespace ::glm; }

	const Vector3 zero = Vector3(0.f, 0.f, 0.f);
	const Vector3 up = Vector3(0.f, 1.f, 0.f);
	const Vector3 forward = Vector3(0.f, 0.f, -1.f);
}


