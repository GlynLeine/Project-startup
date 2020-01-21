#ifndef COLORMATERIAL_HPP
#define COLORMATERIAL_HPP

#include "GL/glew.h"
#include "mge/materials/AbstractMaterial.hpp"


/**
 * This is about the simplest material we can come up with, it demonstrates how to
 * render a single color material without caching, passing in all the matrices we require separately.
 */
class ColorMaterial : public Material<ColorMaterial>
{
public:
	ColorMaterial(glm::vec3 pColor = glm::vec3(1, 0, 0));
	ColorMaterial(glm::vec4 pColor = glm::vec4(1, 0, 0, 1));
	virtual ~ColorMaterial();

	virtual void render(World* pWorld, Mesh* pMesh, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix) override;

	//in rgb values
	void setDiffuseColor(glm::vec3 pDiffuseColor);
	void setDiffuseColor(glm::vec4 pDiffuseColor);

	// Inherited via Material
	virtual void Bind(World * pWorld, const glm::mat4 & pViewMatrix, const glm::mat4 & pProjectionMatrix, Mesh * mesh) override;
	virtual void Release(Mesh * mesh) override;

protected:
	void LazyInitializeShader() override;

private:
	static GLint _uViewProjectionMatrix;
	static GLint _uModelMatrix;
	static GLint _uDiffuseColor;

	static GLint _aVertex;
	static GLint _aNormal;
	static GLint _aUV;

	//this one is unique per instance of color material
	glm::vec4 _diffuseColor;
};

#endif // COLORMATERIAL_HPP
