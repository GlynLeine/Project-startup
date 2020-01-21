#pragma once

#include "mge/materials/AbstractMaterial.hpp"
#include "GL/glew.h"

class ShaderProgram;
class Texture;

/**
 * This material is already a little bit more complicated, instead of a color we can pass in a texture,
 * all attributes and uniforms are cached and we precompute the MVP matrix passing it in as one entity.
 */
class PBRMaterial : public Material<PBRMaterial>
{
public:
	static PBRMaterial* defaultMaterial;

	PBRMaterial(std::string name = "PBR Material",
		Texture* pAlbedo = nullptr, Texture * pNormal = nullptr, Texture* pMetallic = nullptr,
		Texture* pRoughness = nullptr, Texture* pAmbientOcclusion = nullptr,
		Texture* pHeight = nullptr, float pHeightScale = 1.f);

	virtual ~PBRMaterial();

	virtual void render(World* pWorld, Mesh* pMesh, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix) override;

	void setDiffuseTexture(Texture* pAlbedo);

	// Inherited via Material
	virtual void Bind(World * pWorld, const glm::mat4 & pViewMatrix, const glm::mat4 & pProjectionMatrix, Mesh * mesh) override;

	virtual void Release(Mesh * mesh) override;

protected:
	void LazyInitializeShader() override;

private:
	//in this example we cache all identifiers for uniforms & attributes
	static GLint _uViewProjectionMatrix;
	static GLint _uModelMatrix;
	static GLint _uAlbedo;
	static GLint _uNormal;
	static GLint _uMetallic;
	static GLint _uRoughness;
	static GLint _uAO;
	static GLint _uHeight;
	static GLint _uHeightScale;

	static GLint _aVertex;
	static GLint _aNormal;
	static GLint _aUV;
	static GLint _aTangent;

	static GLuint _uboLights;
	static GLint _uLightCount;
	static GLint _uCameraPosition;

	Texture* albedo;
	Texture* normal;
	Texture* metallic;
	Texture* roughness;
	Texture* ambientOcclusion;
	Texture* height;

	float heightScale;

	PBRMaterial(const PBRMaterial&);
	PBRMaterial& operator=(const PBRMaterial&);
};