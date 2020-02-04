#pragma once

#include "glm.hpp"
#include <string>
#include "mge/core/rendering/ShaderProgram.hpp"
#include "mge/config.hpp"
#include "mge/core/rendering/Renderer.hpp"
#include "mge/core/rendering/Mesh.hpp"

class GameObject;
class World;

/**
 * AbstractMaterial should be subclassed for all materials, for example ColorMaterial, LitTextureMaterial.
 *
 * Basically a material is responsible for setting up the correct shader,
 * filling all the correct parameters and actually rendering a mesh by streaming all mesh data through a
 * specific shader. Subclasses often use a static shader variable which is initialized once upon first use,
 * but that is fully optional (!).
 *
 * This works like the Unity Material, where you have to select a shader for a material and the shader chosen
 * determines which properties actually become available for the material itself.
 */
class AbstractMaterial
{
	friend class Renderer;
private:
	static unsigned materialCount;

public:
	const unsigned id = materialCount++;

	const std::string name;

	virtual ~AbstractMaterial();

	/**
	 * Render the given mesh in the given world using the given mvp matrices. Implement in subclass.
	 */
	virtual void render(World* pWorld, Mesh* pMesh, const glm::mat4& pModelMatrix, const glm::mat4& pViewMatrix, const glm::mat4& pPerspectiveMatrix) = 0;
	virtual bool valid() = 0;
	virtual void devalidate() = 0;

	virtual void Bind(World* pWorld, const glm::mat4& pViewMatrix, const glm::mat4& pProjectionMatrix, Mesh* mesh) = 0;
	virtual void Draw(std::vector<glm::mat4>& instances, Mesh* mesh) = 0;
	virtual void Release(Mesh* mesh) = 0;
protected:
	AbstractMaterial(std::string typeName);

	virtual void LazyInitializeShader() = 0;
};

template<typename Self>
class Material : public AbstractMaterial
{
public:
	bool valid();
	void devalidate();

	virtual void Draw(std::vector<glm::mat4>& instances, Mesh* mesh) override;

private:
	static unsigned instanceCount;

protected:
	Material(std::string typeName);

	virtual void LazyInitializeShader() override;

	static ShaderProgram* _shader;
	static GLuint _modelMatrixBufferId;
	static GLint _modelMatrixAttrib;
};

template<typename Self>
unsigned Material<Self>::instanceCount = 0;

template<typename Self>
ShaderProgram* Material<Self>::_shader = nullptr;

template<typename Self>
GLuint Material<Self>::_modelMatrixBufferId = 0;

template<typename Self>
GLint Material<Self>::_modelMatrixAttrib = -1;

template<typename Self>
inline Material<Self>::Material(std::string typeName) : AbstractMaterial(typeName + " " + std::to_string(instanceCount++))
{
}

template<typename Self>
inline void Material<Self>::LazyInitializeShader()
{
	_modelMatrixAttrib = _shader->getAttribLocation("modelMatrix");

	if (_modelMatrixBufferId == 0)
	{
		glGenBuffers(1, &_modelMatrixBufferId);
		glBindBuffer(GL_ARRAY_BUFFER, _modelMatrixBufferId);
		glBufferData(GL_ARRAY_BUFFER, config::MAX_VBO_SIZE, NULL, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
}

template<typename Self>
bool Material<Self>::valid()
{
	return _shader != nullptr;
}

template<typename Self>
void Material<Self>::devalidate()
{
	delete _shader;
	_shader = nullptr;
}

template<typename Self>
inline void Material<Self>::Draw(std::vector<glm::mat4>& instances, Mesh * mesh)
{
	if (_modelMatrixAttrib != -1)
	{
		glBindBuffer(GL_ARRAY_BUFFER, _modelMatrixBufferId);

		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(glm::mat4) * instances.size(), &(instances.data()[0]));

		glEnableVertexAttribArray(_modelMatrixAttrib + 0);
		glEnableVertexAttribArray(_modelMatrixAttrib + 1);
		glEnableVertexAttribArray(_modelMatrixAttrib + 2);
		glEnableVertexAttribArray(_modelMatrixAttrib + 3);

		glVertexAttribPointer(_modelMatrixAttrib + 0, 4, GL_FLOAT, GL_FALSE, 4*sizeof(glm::vec4), (GLvoid*) 0);
		glVertexAttribPointer(_modelMatrixAttrib + 1, 4, GL_FLOAT, GL_FALSE, 4*sizeof(glm::vec4), (GLvoid*)(sizeof(glm::vec4)));
		glVertexAttribPointer(_modelMatrixAttrib + 2, 4, GL_FLOAT, GL_FALSE, 4*sizeof(glm::vec4), (GLvoid*)(2*sizeof(glm::vec4)));
		glVertexAttribPointer(_modelMatrixAttrib + 3, 4, GL_FLOAT, GL_FALSE, 4*sizeof(glm::vec4), (GLvoid*)(3*sizeof(glm::vec4)));

		glVertexAttribDivisor(_modelMatrixAttrib + 0, 1);
		glVertexAttribDivisor(_modelMatrixAttrib + 1, 1);
		glVertexAttribDivisor(_modelMatrixAttrib + 2, 1);
		glVertexAttribDivisor(_modelMatrixAttrib + 3, 1);

	}
	else
	{
		std::cout << "Shader does not contain attribute \"modelMatrix\" in material: " << name << std::endl;
	}

	mesh->Draw(instances.size());

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	if (_modelMatrixAttrib != -1)
	{
		glDisableVertexAttribArray(_modelMatrixAttrib + 0);
		glDisableVertexAttribArray(_modelMatrixAttrib + 1);
		glDisableVertexAttribArray(_modelMatrixAttrib + 2);
		glDisableVertexAttribArray(_modelMatrixAttrib + 3);
	}
}