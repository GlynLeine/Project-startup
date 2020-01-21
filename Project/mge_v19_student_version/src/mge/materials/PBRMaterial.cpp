#include "glm.hpp"

#include "PBRMaterial.hpp"
#include "mge/core/rendering/Texture.hpp"
#include "mge/lights/Light.h"
#include "mge/core/World.hpp"
#include "mge/core/rendering/Mesh.hpp"
#include "mge/core/GameObject.hpp"
#include "mge/config.hpp"
#include "mge/core/rendering/Camera.hpp"

PBRMaterial* PBRMaterial::defaultMaterial = new PBRMaterial("Default");
GLint PBRMaterial::_uViewProjectionMatrix = 0;
GLint PBRMaterial::_uModelMatrix = 0;
GLint PBRMaterial::_uAlbedo = 0;
GLint PBRMaterial::_uNormal = 0;
GLint PBRMaterial::_uMetallic = 0;
GLint PBRMaterial::_uRoughness = 0;
GLint PBRMaterial::_uAO = 0;
GLint PBRMaterial::_uHeight = 0;
GLuint PBRMaterial::_uboLights = 0;
GLint PBRMaterial::_uLightCount = 0;
GLint PBRMaterial::_uCameraPosition = 0;
GLint PBRMaterial::_uHeightScale = 0;

GLint PBRMaterial::_aVertex = 0;
GLint PBRMaterial::_aNormal = 0;
GLint PBRMaterial::_aUV = 0;
GLint PBRMaterial::_aTangent = 0;

PBRMaterial::PBRMaterial(std::string name, Texture* pAlbedoMap, Texture* pNormalMap, Texture* pMetalMap, Texture* pRoughness, Texture* pAmbientOcclusion, Texture* pHeight, float pHeightScale) :
	Material<PBRMaterial>(name),
	albedo(pAlbedoMap), normal(pNormalMap), metallic(pMetalMap), roughness(pRoughness), ambientOcclusion(pAmbientOcclusion), height(pHeight), heightScale(pHeightScale) {
}

PBRMaterial::~PBRMaterial() {}

void PBRMaterial::LazyInitializeShader() {
	if (!_shader) {
		_shader = new ShaderProgram();
		_shader->addShader(GL_VERTEX_SHADER, config::MGE_SHADER_PATH + "littexturePBR.vert");
		_shader->addShader(GL_FRAGMENT_SHADER, config::MGE_SHADER_PATH + "littexturePBR.frag");
		_shader->finalize();

		_shader->use();
		GLuint lightsUniformBlock = _shader->getUniformBlockIndex("LightsBlock");
		_shader->BindUniformBlock(lightsUniformBlock, 0);
		_shader->clearUsage();

		Material<PBRMaterial>::LazyInitializeShader();

		glGenBuffers(1, &_uboLights);
		glBindBuffer(GL_UNIFORM_BUFFER, _uboLights);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(LightData) * config::MAX_LIGHT_COUNT, NULL, GL_DYNAMIC_DRAW);
		glBindBufferBase(GL_UNIFORM_BUFFER, 0, _uboLights);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);

		//cache all the uniform and attribute indexes
		_uViewProjectionMatrix = _shader->getUniformLocation("viewProjectionMatrix");
		_uModelMatrix = _shader->getUniformLocation("modelMatrix");
		_uAlbedo = _shader->getUniformLocation("albedoMap");
		_uNormal = _shader->getUniformLocation("normalMap");
		_uMetallic = _shader->getUniformLocation("metalMap");
		_uRoughness = _shader->getUniformLocation("roughnessMap");
		_uAO = _shader->getUniformLocation("aoMap");
		_uHeight = _shader->getUniformLocation("heightMap");
		_uLightCount = _shader->getUniformLocation("lightCount");
		_uCameraPosition = _shader->getUniformLocation("cameraPosition");
		_uHeightScale = _shader->getUniformLocation("heightScale");

		_aVertex = _shader->getAttribLocation("vertex");
		_aNormal = _shader->getAttribLocation("normal");
		_aUV = _shader->getAttribLocation("uv");
		_aTangent = _shader->getAttribLocation("tangent");
	}
}

void PBRMaterial::Bind(World * pWorld, const glm::mat4 & pViewMatrix, const glm::mat4 & pProjectionMatrix, Mesh * mesh)
{
	if (!albedo)
	{
		std::cout << "Albedo map for material " << name << " is missing!!!" << std::endl;
		albedo = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-albedo.png");
	}
	if (!normal)
	{
		std::cout << "Normal map for material " << name << " is missing!!!" << std::endl;
		normal = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-normal.png");
	}
	if (!metallic)
	{
		std::cout << "Metallic map for material " << name << " is missing!!!" << std::endl;
		metallic = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-metal.png");
	}
	if (!roughness)
	{
		std::cout << "Roughness map for material " << name << " is missing!!!" << std::endl;
		roughness = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-roughness.png");
	}
	if (!ambientOcclusion)
	{
		std::cout << "Ambient occlusion map for material " << name << " is missing!!!" << std::endl;
		ambientOcclusion = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-ao.png");
	}
	if (!height)
	{
		std::cout << "Height map for material " << name << " is missing!!!" << std::endl;
		height = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-height.png");
	}

	_shader->use();

	LightData lights[config::MAX_LIGHT_COUNT];
	for (int i = 0; i < pWorld->getLightCount(); i++)
		lights[i] = pWorld->getLightAt(i)->getLightData();

	glBindBuffer(GL_UNIFORM_BUFFER, _uboLights);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(LightData) * pWorld->getLightCount(), lights);

	glUniform1i(_uAlbedo, 0);
	glUniform1i(_uNormal, 1);
	glUniform1i(_uMetallic, 2);
	glUniform1i(_uRoughness, 3);
	glUniform1i(_uAO, 4);
	glUniform1i(_uHeight, 5);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, albedo->getId());

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, normal->getId());

	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, metallic->getId());

	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, roughness->getId());

	glActiveTexture(GL_TEXTURE4);
	glBindTexture(GL_TEXTURE_2D, ambientOcclusion->getId());

	glActiveTexture(GL_TEXTURE5);
	glBindTexture(GL_TEXTURE_2D, height->getId());


	glUniform1f(_uHeightScale, heightScale);
	glUniform1i(_uLightCount, pWorld->getLightCount());
	glUniform3fv(_uCameraPosition, 1, glm::value_ptr(pWorld->getMainCamera()->getWorldPosition()));

	//pass in a precalculate mvp matrix (see texture material for the opposite)
	glm::mat4 vpMatrix = pProjectionMatrix * pViewMatrix;
	glUniformMatrix4fv(_uViewProjectionMatrix, 1, GL_FALSE, glm::value_ptr(vpMatrix));

	mesh->Bind(_aVertex, _aNormal, _aUV, _aTangent);
}

void PBRMaterial::Release(Mesh * mesh)
{
	mesh->Unbind(_aVertex, _aNormal, _aUV, _aTangent);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	_shader->clearUsage();
}

void PBRMaterial::setDiffuseTexture(Texture* pAlbedoMap) {
	albedo = pAlbedoMap;
}

void PBRMaterial::render(World* pWorld, Mesh* pMesh, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix) {
	if (!albedo)
	{
		std::cout << "Albedo map for material " << name << " is missing!!!" << std::endl;
		albedo = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-albedo.png");
	}
	if (!normal)
	{
		std::cout << "Normal map for material " << name << " is missing!!!" << std::endl;
		normal = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-normal.png");
	}
	if (!metallic)
	{
		std::cout << "Metallic map for material " << name << " is missing!!!" << std::endl;
		metallic = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-metal.png");
	}
	if (!roughness)
	{
		std::cout << "Roughness map for material " << name << " is missing!!!" << std::endl;
		roughness = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-roughness.png");
	}
	if (!ambientOcclusion)
	{
		std::cout << "Ambient occlusion map for material " << name << " is missing!!!" << std::endl;
		ambientOcclusion = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-ao.png");
	}
	if (!height)
	{
		std::cout << "Height map for material " << name << " is missing!!!" << std::endl;
		height = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-height.png");
	}

	_shader->use();

	LightData lights[config::MAX_LIGHT_COUNT];
	for (int i = 0; i < pWorld->getLightCount(); i++)
		lights[i] = pWorld->getLightAt(i)->getLightData();

	glBindBuffer(GL_UNIFORM_BUFFER, _uboLights);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(LightData) * pWorld->getLightCount(), lights);

	glUniform1i(_uAlbedo, 0);
	glUniform1i(_uNormal, 1);
	glUniform1i(_uMetallic, 2);
	glUniform1i(_uRoughness, 3);
	glUniform1i(_uAO, 4);
	glUniform1i(_uHeight, 5);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, albedo->getId());

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, normal->getId());

	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D, metallic->getId());

	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D, roughness->getId());

	glActiveTexture(GL_TEXTURE4);
	glBindTexture(GL_TEXTURE_2D, ambientOcclusion->getId());

	glActiveTexture(GL_TEXTURE5);
	glBindTexture(GL_TEXTURE_2D, height->getId());


	glUniform1f(_uHeightScale, heightScale);
	glUniform1i(_uLightCount, pWorld->getLightCount());
	glUniform3fv(_uCameraPosition, 1, glm::value_ptr(pWorld->getMainCamera()->getWorldPosition()));

	//pass in a precalculate mvp matrix (see texture material for the opposite)
	glm::mat4 vpMatrix = pProjectionMatrix * pViewMatrix;
	glUniformMatrix4fv(_uViewProjectionMatrix, 1, GL_FALSE, glm::value_ptr(vpMatrix));
	glUniformMatrix4fv(_uModelMatrix, 1, GL_FALSE, glm::value_ptr(pModelMatrix));

	//now inform mesh of where to stream its data
	pMesh->StreamToOpenGL(_aVertex, _aNormal, _aUV, _aTangent);

	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	_shader->clearUsage();
}
