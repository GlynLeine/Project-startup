#pragma once
#include <glad/glad.h>
#include <vector>
#include <string>
#include <Args-Core.h>

namespace Args
{
	class Mesh;
	struct Camera;

	/**
	 * Generic shader program to which you can add separate shaders.
	 * Nice exercise for the reader: make it possible to add shaders by passing in the code as a string instead of through a file.
	 *
	 * Usage:
	 *  -create shader program
	 *  -add shaders
	 *  -finalize shader program
	 *  -use shader program
	 *
	 * See the example material classes for a demo.
	 */
	class Shader
	{
	public:
		Shader(const std::string& name);
		virtual ~Shader();

		//add a shader of a specific type (eg GL_VERTEX_SHADER / GL_FRAGMENT_SHADER)
		void AddShader(GLuint pShaderType, const std::string& pShaderPath);
		//link and compile all added shaders
		void Finalize();
		//tell opengl this is now the current shader program
		void Bind(Mesh* mesh);
		void Render(std::vector<glm::mat4>& instances, Mesh* mesh, Camera* camera);
		void Release(Mesh* mesh);

		GLuint getUniformBlockIndex(const std::string& pName);
		void BindUniformBlock(GLuint uniformBlockIndex, GLuint uniformBlockBinding);

		//get access to uniforms within the shader
		GLuint getUniformLocation(const std::string& pName);
		//get access to attributes within the shader
		GLuint getAttribLocation(const std::string& pName);

	private:
		std::string name;

		GLint _programId;
		GLuint _modelMatrixBufferId;
		GLint _modelMatrixAttrib;

		GLint _uCameraPosition;
		GLint _uViewProjectionMatrix;

		GLint _aVertex;
		GLint _aNormal;
		GLint _aUV;
		GLint _aTangent;

		std::vector<GLuint> _shaderIds;

		std::string _readFile(const std::string& pShaderPath);
		GLuint _compileShader(GLuint pShaderType, const std::string& pShaderSource);
	};
}