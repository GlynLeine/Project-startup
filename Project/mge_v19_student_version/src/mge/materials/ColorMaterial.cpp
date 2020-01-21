#include "glm.hpp"

#include "ColorMaterial.hpp"
#include "mge/config.hpp"
#include "mge/core/GameObject.hpp"
#include "mge/core/rendering/Mesh.hpp"

GLint ColorMaterial::_uViewProjectionMatrix = 0;
GLint ColorMaterial::_uModelMatrix = 0;
GLint ColorMaterial::_uDiffuseColor = 0;

GLint ColorMaterial::_aVertex = 0;
GLint ColorMaterial::_aNormal = 0;
GLint ColorMaterial::_aUV = 0;

ColorMaterial::ColorMaterial(glm::vec3 pDiffuseColor) : Material<ColorMaterial>("Color material"), _diffuseColor(glm::vec4(pDiffuseColor, 1.f))
{
}

ColorMaterial::ColorMaterial(glm::vec4 pDiffuseColor) : Material<ColorMaterial>("Color material"), _diffuseColor(pDiffuseColor)
{
}

void ColorMaterial::LazyInitializeShader() {
    //this shader contains everything the material can do (it can render something in 3d using a single color)
    if (!_shader) {
        _shader = new ShaderProgram();
        _shader->addShader(GL_VERTEX_SHADER, config::MGE_SHADER_PATH+"colorvert.glsl");
        _shader->addShader(GL_FRAGMENT_SHADER, config::MGE_SHADER_PATH+"colorfrag.glsl");
        _shader->finalize();

		Material<ColorMaterial>::LazyInitializeShader();

		_uViewProjectionMatrix = _shader->getUniformLocation("viewProjectionMatrix");
		_uModelMatrix = _shader->getUniformLocation("modelMatrix");
		_uDiffuseColor = _shader->getUniformLocation("diffuseColor");

		_aVertex = _shader->getAttribLocation("vertex");
		_aNormal = _shader->getAttribLocation("normal");
		_aUV = _shader->getAttribLocation("uv");
    }
}

void ColorMaterial::Bind(World * pWorld, const glm::mat4 & pViewMatrix, const glm::mat4 & pProjectionMatrix, Mesh * mesh)
{
	_shader->use();

	//set the material color
	glUniform4fv(_uDiffuseColor, 1, glm::value_ptr(_diffuseColor));

	glm::mat4 vpMatrix = pProjectionMatrix * pViewMatrix;
	glUniformMatrix4fv(_uViewProjectionMatrix, 1, GL_FALSE, glm::value_ptr(vpMatrix));

	mesh->Bind(_aVertex, _aNormal, _aUV);
}

void ColorMaterial::Release(Mesh * mesh)
{
	mesh->Unbind(_aVertex, _aNormal, _aUV);
	_shader->clearUsage();
}

ColorMaterial::~ColorMaterial()
{
    //dtor
}

void ColorMaterial::setDiffuseColor(glm::vec3 pDiffuseColor) {
    _diffuseColor = glm::vec4(pDiffuseColor, 1.f);
}

void ColorMaterial::setDiffuseColor(glm::vec4 pDiffuseColor)
{
	_diffuseColor = pDiffuseColor;
}

void ColorMaterial::render(World* pWorld, Mesh* pMesh, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix) {
    _shader->use();

    //set the material color
    glUniform4fv (_uDiffuseColor, 1, glm::value_ptr(_diffuseColor));

    //pass in all MVP matrices separately
	glm::mat4 vpMatrix = pProjectionMatrix * pViewMatrix;
	glUniformMatrix4fv(_uViewProjectionMatrix, 1, GL_FALSE, glm::value_ptr(vpMatrix));
	glUniformMatrix4fv(_uModelMatrix, 1, GL_FALSE, glm::value_ptr(pModelMatrix));

    //now inform mesh of where to stream its data
	pMesh->StreamToOpenGL(_aVertex, _aNormal, _aUV);


}
