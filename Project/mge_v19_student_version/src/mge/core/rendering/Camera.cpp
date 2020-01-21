#include "glm.hpp"
#include "mge/core/rendering/Camera.hpp"

glm::mat4 Camera::defProjectionMatrix = glm::perspective(glm::radians(90.0f), 16.0f / 9.0f, 0.1f, 1000.0f);


Camera::Camera( std::string pName, glm::vec3 pPosition, bool useDefault, glm::mat4 pProjectionMatrix )
:	GameObject(pName, pPosition), useDefault(useDefault), _projection(pProjectionMatrix)
{
}

Camera::~Camera()
{
	//dtor
}

glm::mat4& Camera::getProjection() {
	if (useDefault)
		return defProjectionMatrix;
    return _projection;
}

