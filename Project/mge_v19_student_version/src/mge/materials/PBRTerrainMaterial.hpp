#pragma once

#include "mge/materials/AbstractMaterial.hpp"
#include "GL/glew.h"
#include <array>

class ShaderProgram;
class Texture;
class TextureArray;
class PBRMaterial;

/**
 * This material is already a little bit more complicated, instead of a color we can pass in a texture,
 * all attributes and uniforms are cached and we precompute the MVP matrix passing it in as one entity.
 */
class PBRTerrainMaterial : public Material<PBRTerrainMaterial>
{
public:
	PBRTerrainMaterial(std::string name = "PBR Terrain Material", Texture* heightMap = nullptr, float pHeightScale = 1.f, Texture* splatMap = nullptr,
		PBRMaterial* mat1 = nullptr, PBRMaterial* mat2 = nullptr, PBRMaterial* mat3 = nullptr, PBRMaterial* mat4 = nullptr);

	PBRTerrainMaterial(std::string name = "PBR Terrain Material", Texture* heightMap = nullptr, float pHeightScale = 1.f, Texture* normalMap = nullptr, Texture* splatMap = nullptr,
		PBRMaterial* mat1 = nullptr, PBRMaterial* mat2 = nullptr, PBRMaterial* mat3 = nullptr, PBRMaterial* mat4 = nullptr);

	virtual ~PBRTerrainMaterial();

	virtual void render(World* pWorld, Mesh* pMesh, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix) override;

	// Inherited via Material
	virtual void Bind(World * pWorld, const glm::mat4 & pViewMatrix, const glm::mat4 & pProjectionMatrix, Mesh * mesh) override;

	virtual void Release(Mesh * mesh) override;

protected:
	void LazyInitializeShader() override;

private:
	//in this example we cache all identifiers for uniforms & attributes
	static GLint _uViewProjectionMatrix;
	static GLint _uModelMatrix;
	static GLint _uSplat;
	static GLint _uTerrain;
	static GLint _uTerrainNormal;
	static GLint _uTerrainScale;
	static GLint _uAlbedo;
	static GLint _uNormal;
	static GLint _uMetallic;
	static GLint _uRoughness;
	static GLint _uAO;
	static GLint _uHeight;
	static GLint _uHeightScale;
	static GLint _uTerrainUVScale;

	static GLint _aVertex;
	static GLint _aNormal;
	static GLint _aUV;
	static GLint _aTangent;

	static GLuint _uboLights;
	static GLint _uLightCount;
	static GLint _uCameraPosition;

	TextureArray* albedo;
	TextureArray* normal;
	TextureArray* metallic;
	TextureArray* roughness;
	TextureArray* ambientOcclusion;
	TextureArray* height;
	std::array<float, 4> heightScale;

	Texture* splatMap;
	Texture* terrainMap;
	Texture* terrainNormalMap;
	float terrainScale;
	glm::vec2 terrainUVScale;
	std::array<PBRMaterial*, 4> materials;

	PBRTerrainMaterial(const PBRTerrainMaterial&);
	PBRTerrainMaterial& operator=(const PBRTerrainMaterial&);
};