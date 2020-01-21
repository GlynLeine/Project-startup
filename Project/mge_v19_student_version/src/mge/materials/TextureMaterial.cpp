#include "glm.hpp"

#include "TextureMaterial.hpp"
#include "mge/core/rendering/Texture.hpp"
#include "mge/lights/Light.h"
#include "mge/core/World.hpp"
#include "mge/core/rendering/Mesh.hpp"
#include "mge/core/GameObject.hpp"
#include "mge/config.hpp"

GLint TextureMaterial::_uModelMatrix = 0;
GLint TextureMaterial::_uViewProjectionMatrix = 0;
GLint TextureMaterial::_uDiffuseTexture = 0;

GLint TextureMaterial::_aVertex = 0;
GLint TextureMaterial::_aNormal = 0;
GLint TextureMaterial::_aUV = 0;

TextureMaterial::TextureMaterial(Texture * pDiffuseTexture) : Material<TextureMaterial>("Texture material"), _diffuseTexture(pDiffuseTexture) {
}

TextureMaterial::~TextureMaterial() {}

void TextureMaterial::LazyInitializeShader() {
    if (!_shader) {
        _shader = new ShaderProgram();
        _shader->addShader(GL_VERTEX_SHADER, config::MGE_SHADER_PATH+"texturevert.glsl");
        _shader->addShader(GL_FRAGMENT_SHADER, config::MGE_SHADER_PATH+"texturefrag.glsl");
        _shader->finalize();

		Material<TextureMaterial>::LazyInitializeShader();

        //cache all the uniform and attribute indexes
		_uViewProjectionMatrix = _shader->getUniformLocation("viewProjectionMatrix");
		_uModelMatrix = _shader->getUniformLocation("modelMatrix");
		_uDiffuseTexture = _shader->getUniformLocation("diffuseTexture");

        _aVertex = _shader->getAttribLocation("vertex");
        _aNormal = _shader->getAttribLocation("normal");
        _aUV =     _shader->getAttribLocation("uv");
    }
}

void TextureMaterial::Bind(World * pWorld, const glm::mat4 & pViewMatrix, const glm::mat4 & pProjectionMatrix, Mesh * mesh)
{
	if (!_diffuseTexture) return;
	_shader->use();

	//setup texture slot 0
	glActiveTexture(GL_TEXTURE0);
	//bind the texture to the current active slot
	glBindTexture(GL_TEXTURE_2D, _diffuseTexture->getId());
	//tell the shader the texture slot for the diffuse texture is slot 0
	glUniform1i(_uDiffuseTexture, 0);

	//pass in a precalculate mvp matrix (see texture material for the opposite)
	glm::mat4 vpMatrix = pProjectionMatrix * pViewMatrix;
	glUniformMatrix4fv(_uViewProjectionMatrix, 1, GL_FALSE, glm::value_ptr(vpMatrix));
}

void TextureMaterial::Draw(std::vector<glm::mat4>& instances, Mesh * mesh)
{
	if (!_diffuseTexture) return;

	Material<TextureMaterial>::Draw(instances, mesh);
}

void TextureMaterial::Release(Mesh * mesh)
{
	if (!_diffuseTexture) return;
	_shader->clearUsage();
}

void TextureMaterial::setDiffuseTexture (Texture* pDiffuseTexture) {
    _diffuseTexture = pDiffuseTexture;
}

void TextureMaterial::render(World* pWorld, Mesh* pMesh, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix) {
    if (!_diffuseTexture) return;

    _shader->use();

    //Print the number of lights in the scene and the position of the first light.
    //It is not used, but this demo is just meant to show you THAT materials can access the lights in a world
    //if (pWorld->getLightCount() > 0) {
    //    std::cout << "TextureMaterial has discovered light is at position:" << pWorld->getLightAt(0)->getLocalPosition() << std::endl;
    //}

    //setup texture slot 0
    glActiveTexture(GL_TEXTURE0);
    //bind the texture to the current active slot
    glBindTexture(GL_TEXTURE_2D, _diffuseTexture->getId());
    //tell the shader the texture slot for the diffuse texture is slot 0
    glUniform1i (_uDiffuseTexture, 0);

    //pass in a precalculate mvp matrix (see texture material for the opposite)
    glm::mat4 vpMatrix = pProjectionMatrix * pViewMatrix;
    glUniformMatrix4fv (_uViewProjectionMatrix, 1, GL_FALSE, glm::value_ptr(vpMatrix));
	glUniformMatrix4fv(_uModelMatrix, 1, GL_FALSE, glm::value_ptr(pModelMatrix));

    //now inform mesh of where to stream its data
    pMesh->StreamToOpenGL(_aVertex, _aNormal, _aUV);

	_shader->clearUsage();
}
