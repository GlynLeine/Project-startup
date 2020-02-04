#include "glm.hpp"

#include "PBRTerrainMaterial.hpp"
#include "mge/core/rendering/Texture.hpp"
#include "mge/core/rendering/TextureArray.hpp"
#include "mge/lights/Light.h"
#include "mge/core/World.hpp"
#include "mge/core/rendering/Mesh.hpp"
#include "mge/core/GameObject.hpp"
#include "mge/config.hpp"
#include "mge/core/rendering/Camera.hpp"
#include "mge/materials/PBRMaterial.hpp"

GLint PBRTerrainMaterial::_uViewProjectionMatrix = 0;
GLint PBRTerrainMaterial::_uModelMatrix = 0;
GLint PBRTerrainMaterial::_uSplat = 0;
GLint PBRTerrainMaterial::_uTerrain = 0;
GLint PBRTerrainMaterial::_uTerrainNormal = 0;
GLuint PBRTerrainMaterial::_uboLights = 0;
GLint PBRTerrainMaterial::_uLightCount = 0;
GLint PBRTerrainMaterial::_uCameraPosition = 0;
GLint PBRTerrainMaterial::_uTerrainScale = 0;
GLint PBRTerrainMaterial::_uAlbedo = 0;
GLint PBRTerrainMaterial::_uNormal = 0;
GLint PBRTerrainMaterial::_uMetallic = 0;
GLint PBRTerrainMaterial::_uRoughness = 0;
GLint PBRTerrainMaterial::_uAO = 0;
GLint PBRTerrainMaterial::_uHeight = 0;
GLint PBRTerrainMaterial::_uHeightScale = 0;
GLint PBRTerrainMaterial::_uTerrainUVScale = 0;

GLint PBRTerrainMaterial::_aVertex = 0;
GLint PBRTerrainMaterial::_aNormal = 0;
GLint PBRTerrainMaterial::_aUV = 0;
GLint PBRTerrainMaterial::_aTangent = 0;

PBRTerrainMaterial::PBRTerrainMaterial(std::string name, Texture* heightMap, float pHeightScale, Texture* splatMap,
	PBRMaterial* mat1, PBRMaterial* mat2, PBRMaterial* mat3, PBRMaterial* mat4) :
	Material<PBRTerrainMaterial>(name), terrainMap(heightMap), terrainScale(pHeightScale), terrainNormalMap(nullptr), splatMap(splatMap)
{
	std::array<Texture*, 4> albedos = { mat1->getAlbedo(), mat2->getAlbedo(), mat3->getAlbedo(), mat4->getAlbedo() };
	std::array<Texture*, 4> normals = { mat1->getNormal(), mat2->getNormal(), mat3->getNormal(), mat4->getNormal() };
	std::array<Texture*, 4> metallics = { mat1->getMetallic(), mat2->getMetallic(), mat3->getMetallic(), mat4->getMetallic() };
	std::array<Texture*, 4> roughnesss = { mat1->getRoughness(), mat2->getRoughness(), mat3->getRoughness(), mat4->getRoughness() };
	std::array<Texture*, 4> ambientOcclusions = { mat1->getAmbientOcclusion(), mat2->getAmbientOcclusion(), mat3->getAmbientOcclusion(), mat4->getAmbientOcclusion() };
	std::array<Texture*, 4> heights = { mat1->getHeight(), mat2->getHeight(), mat3->getHeight(), mat4->getHeight() };
	albedo = TextureArray::generateTextureArray(albedos, false);
	normal = TextureArray::generateTextureArray(normals, false);
	metallic = TextureArray::generateTextureArray(metallics, false);
	roughness = TextureArray::generateTextureArray(roughnesss, false);
	ambientOcclusion = TextureArray::generateTextureArray(ambientOcclusions, false);
	height = TextureArray::generateTextureArray(heights, false);
	heightScale = { mat1->getHeightScale() * 10, mat2->getHeightScale() * 10, mat3->getHeightScale() * 10, mat4->getHeightScale() * 10 };
	terrainUVScale = glm::vec2(1.f / heightMap->getImageData()->getSize().x, 1.f / heightMap->getImageData()->getSize().y);
}

PBRTerrainMaterial::PBRTerrainMaterial(std::string name, Texture * heightMap, float pHeightScale, Texture * normalMap, Texture * splatMap,
	PBRMaterial * mat1, PBRMaterial * mat2, PBRMaterial * mat3, PBRMaterial * mat4) :
	Material<PBRTerrainMaterial>(name), terrainMap(heightMap), terrainScale(pHeightScale), terrainNormalMap(normalMap), splatMap(splatMap)
{
	std::array<Texture*, 4> albedos = { mat1->getAlbedo(), mat2->getAlbedo(), mat3->getAlbedo(), mat4->getAlbedo() };
	std::array<Texture*, 4> normals = { mat1->getNormal(), mat2->getNormal(), mat3->getNormal(), mat4->getNormal() };
	std::array<Texture*, 4> metallics = { mat1->getMetallic(), mat2->getMetallic(), mat3->getMetallic(), mat4->getMetallic() };
	std::array<Texture*, 4> roughnesss = { mat1->getRoughness(), mat2->getRoughness(), mat3->getRoughness(), mat4->getRoughness() };
	std::array<Texture*, 4> ambientOcclusions = { mat1->getAmbientOcclusion(), mat2->getAmbientOcclusion(), mat3->getAmbientOcclusion(), mat4->getAmbientOcclusion() };
	std::array<Texture*, 4> heights = { mat1->getHeight(), mat2->getHeight(), mat3->getHeight(), mat4->getHeight() };
	albedo = TextureArray::generateTextureArray(albedos, false);
	normal = TextureArray::generateTextureArray(normals, false);
	metallic = TextureArray::generateTextureArray(metallics, false);
	roughness = TextureArray::generateTextureArray(roughnesss, false);
	ambientOcclusion = TextureArray::generateTextureArray(ambientOcclusions, false);
	height = TextureArray::generateTextureArray(heights, false);
	heightScale = { mat1->getHeightScale() * 10, mat2->getHeightScale() * 10, mat3->getHeightScale() * 10, mat4->getHeightScale() * 10 };
	terrainUVScale = glm::vec2(1.f / heightMap->getImageData()->getSize().x, 1.f / heightMap->getImageData()->getSize().y);
}

PBRTerrainMaterial::~PBRTerrainMaterial() {}

void PBRTerrainMaterial::LazyInitializeShader() {
	if (!_shader) {
		_shader = new ShaderProgram();
		if (terrainNormalMap == nullptr)
		{
			_shader->addShader(GL_VERTEX_SHADER, config::MGE_SHADER_PATH + "littextureTerrainPBR.vert");
			_shader->addShader(GL_FRAGMENT_SHADER, config::MGE_SHADER_PATH + "littextureTerrainPBR.frag");
		}
		else
		{
			_shader->addShader(GL_VERTEX_SHADER, config::MGE_SHADER_PATH + "littextureTerrainPBRNormal.vert");
			_shader->addShader(GL_FRAGMENT_SHADER, config::MGE_SHADER_PATH + "littextureTerrainPBRNormal.frag");
		}
		_shader->finalize();

		_shader->use();
		GLuint lightsUniformBlock = _shader->getUniformBlockIndex("LightsBlock");
		_shader->BindUniformBlock(lightsUniformBlock, 0);
		_shader->clearUsage();

		Material<PBRTerrainMaterial>::LazyInitializeShader();

		glGenBuffers(1, &_uboLights);
		glBindBuffer(GL_UNIFORM_BUFFER, _uboLights);
		glBufferData(GL_UNIFORM_BUFFER, sizeof(LightData) * config::MAX_LIGHT_COUNT, NULL, GL_DYNAMIC_DRAW);
		glBindBufferBase(GL_UNIFORM_BUFFER, 0, _uboLights);
		glBindBuffer(GL_UNIFORM_BUFFER, 0);

		//cache all the uniform and attribute indexes
		_uViewProjectionMatrix = _shader->getUniformLocation("viewProjectionMatrix");
		_uModelMatrix = _shader->getUniformLocation("modelMatrix");
		_uLightCount = _shader->getUniformLocation("lightCount");
		_uCameraPosition = _shader->getUniformLocation("cameraPosition");
		_uSplat = _shader->getUniformLocation("splatMap");
		_uTerrain = _shader->getUniformLocation("terrainMap");
		_uTerrainScale = _shader->getUniformLocation("terrainScale");
		_uTerrainUVScale = _shader->getUniformLocation("terrainUVScale");

		if (terrainNormalMap != nullptr)
			_uTerrainNormal = _shader->getUniformLocation("terrainNormalMap");

		_uAlbedo = _shader->getUniformLocation("albedoMap");
		_uNormal = _shader->getUniformLocation("normalMap");
		_uMetallic = _shader->getUniformLocation("metalMap");
		_uRoughness = _shader->getUniformLocation("roughnessMap");
		_uAO = _shader->getUniformLocation("aoMap");
		_uHeight = _shader->getUniformLocation("heightMap");
		_uHeightScale = _shader->getUniformLocation("heightScale");

		_aVertex = _shader->getAttribLocation("vertex");
		_aNormal = _shader->getAttribLocation("normal");
		_aUV = _shader->getAttribLocation("uv");
		_aTangent = _shader->getAttribLocation("tangent");
	}
}

void PBRTerrainMaterial::Bind(World * pWorld, const glm::mat4 & pViewMatrix, const glm::mat4 & pProjectionMatrix, Mesh * mesh)
{
	if (!splatMap)
	{
		std::cout << "Splat map for material " << name << " is missing!!!" << std::endl;
		splatMap = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-normal.png");
	}
	if (!terrainMap)
	{
		std::cout << "Height map for material " << name << " is missing!!!" << std::endl;
		terrainMap = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-height.png");
	}

	_shader->use();

	LightData lights[config::MAX_LIGHT_COUNT];
	for (int i = 0; i < pWorld->getLightCount(); i++)
		lights[i] = pWorld->getLightAt(i)->getLightData();

	glBindBuffer(GL_UNIFORM_BUFFER, _uboLights);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(LightData) * pWorld->getLightCount(), lights);

	glUniform1i(_uTerrain, 0);
	glUniform1i(_uSplat, 1);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, terrainMap->getId());

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, splatMap->getId());

	glUniform1i(_uAlbedo, 2);
	glUniform1i(_uNormal, 3);
	glUniform1i(_uMetallic, 4);
	glUniform1i(_uRoughness, 5);
	glUniform1i(_uAO, 6);
	glUniform1i(_uHeight, 7);

	glActiveTexture(GL_TEXTURE2);
	glBindTexture(GL_TEXTURE_2D_ARRAY, albedo->getId());

	glActiveTexture(GL_TEXTURE3);
	glBindTexture(GL_TEXTURE_2D_ARRAY, normal->getId());

	glActiveTexture(GL_TEXTURE4);
	glBindTexture(GL_TEXTURE_2D_ARRAY, metallic->getId());

	glActiveTexture(GL_TEXTURE5);
	glBindTexture(GL_TEXTURE_2D_ARRAY, roughness->getId());

	glActiveTexture(GL_TEXTURE6);
	glBindTexture(GL_TEXTURE_2D_ARRAY, ambientOcclusion->getId());

	glActiveTexture(GL_TEXTURE7);
	glBindTexture(GL_TEXTURE_2D_ARRAY, height->getId());

	if (terrainNormalMap != nullptr)
	{
		glUniform1i(_uTerrainNormal, 8);
		glActiveTexture(GL_TEXTURE8);
		glBindTexture(GL_TEXTURE_2D, terrainNormalMap->getId());
	}

	glUniform1f(_uTerrainScale, terrainScale);
	glUniform1i(_uLightCount, pWorld->getLightCount());
	glUniform3fv(_uCameraPosition, 1, glm::value_ptr(pWorld->getMainCamera()->getWorldPosition()));
	glUniform2fv(_uTerrainUVScale, 1, glm::value_ptr(terrainUVScale));

	// TO DO: SEND PBR MATERIAL TEXTURES...

	//pass in a precalculate mvp matrix (see texture material for the opposite)
	glm::mat4 vpMatrix = pProjectionMatrix * pViewMatrix;
	glUniformMatrix4fv(_uViewProjectionMatrix, 1, GL_FALSE, glm::value_ptr(vpMatrix));

	mesh->Bind(_aVertex, _aNormal, _aUV, _aTangent);
}

void PBRTerrainMaterial::Release(Mesh * mesh)
{
	mesh->Unbind(_aVertex, _aNormal, _aUV, _aTangent);
	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	_shader->clearUsage();
}

void PBRTerrainMaterial::render(World* pWorld, Mesh* pMesh, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix) {
	if (!splatMap)
	{
		std::cout << "Splat map for material " << name << " is missing!!!" << std::endl;
		splatMap = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-normal.png");
	}
	if (!terrainMap)
	{
		std::cout << "Height map for material " << name << " is missing!!!" << std::endl;
		terrainMap = Texture::load(config::MGE_TEXTURE_PATH + "Default/default-height.png");
	}

	_shader->use();

	LightData lights[config::MAX_LIGHT_COUNT];
	for (int i = 0; i < pWorld->getLightCount(); i++)
		lights[i] = pWorld->getLightAt(i)->getLightData();

	glBindBuffer(GL_UNIFORM_BUFFER, _uboLights);
	glBufferSubData(GL_UNIFORM_BUFFER, 0, sizeof(LightData) * pWorld->getLightCount(), lights);

	glUniform1i(_uTerrain, 0);
	glUniform1i(_uSplat, 1);

	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, terrainMap->getId());

	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, splatMap->getId());


	glUniform1f(_uTerrainScale, terrainScale);
	glUniform1i(_uLightCount, pWorld->getLightCount());
	glUniform3fv(_uCameraPosition, 1, glm::value_ptr(pWorld->getMainCamera()->getWorldPosition()));

	//pass in a precalculate mvp matrix (see texture material for the opposite)
	glm::mat4 vpMatrix = pProjectionMatrix * pViewMatrix;
	glUniformMatrix4fv(_uViewProjectionMatrix, 1, GL_FALSE, glm::value_ptr(vpMatrix));
	glUniformMatrix4fv(_uModelMatrix, 1, GL_FALSE, glm::value_ptr(pModelMatrix));

	// TO DO: SEND PBR MATERIAL TEXTURES...

	//now inform mesh of where to stream its data
	pMesh->StreamToOpenGL(_aVertex, _aNormal, _aUV, _aTangent);

	glBindBuffer(GL_UNIFORM_BUFFER, 0);
	_shader->clearUsage();
}
