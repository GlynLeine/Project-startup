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
		//static Shader* LoadShader(const std::string& name, const std::string& vertexShader, const std::string& fragmentShader);

		//tell opengl this is now the current shader program
		void Bind(Mesh* mesh) const;
		void Render(std::vector<Matrix4>& instances, Mesh* mesh, Camera* camera) const;
		void Release(Mesh* mesh) const;

		GLuint GetUniformBlockIndex(const std::string& pName) const;
		void BindUniformBlock(GLuint uniformBlockIndex, GLuint uniformBlockBinding) const;

		//get access to uniforms within the shader
		GLuint GetUniformLocation(const std::string& pName) const;
		//get access to attributes within the shader
		GLuint GetAttribLocation(const std::string& pName) const;

		// TO DO: automatic attribute and uniform detection


	private:
		std::string name;

		GLint programId;
		GLuint modelMatrixBufferId;
		GLint modelMatrixAttrib;

		GLint cameraPositionUniform;
		GLint viewProjectionMatrixUniform;

		GLint vertexAttrib;
		GLint normalAttrib;
		GLint uvAttrib;
		GLint tangentAttrib;

		std::vector<GLuint> shaderIds;
		//static std::unordered_map<std::pair<const std::string&, const std::string&>, Shader*> shaders;

		Shader(const std::string& name);
		//link and compile all added shaders
		void Finalize();
		//add a shader of a specific type (eg GL_VERTEX_SHADER / GL_FRAGMENT_SHADER)
		void AddShader(GLuint pShaderType, const std::string& pShaderPath);
		std::string ReadFile(const std::string& shaderPath);
		GLuint CompileShader(GLuint shaderType, const std::string& shaderSource);

		void ProcessIncludes(std::string& shaderSource);

	};

	template<typename T>
	class Uniform
	{
	private:
		Shader* shader;
		std::string		name;
		GLenum			type;
		GLint			location;
		GLint			sampler;

	public:
		Uniform(Shader* shader, std::string name, GLint location, GLint sampler = -1);

		bool IsValid() const;
		GLenum GetType() const;
		GLint GetLocation() const;
		void SetValue(T value);
	};


	class Attribute
	{
	private:
		Shader* shader;
		std::string  name;
		GLenum		type;
		GLint		location;

	public:
		/// The shader creates a parameter.
		Attribute(Shader* shader, std::string name, GLenum type, GLint location);

		bool IsValid() const;
		GLenum GetType() const;
		GLint GetLocation() const;

		/// Check documentation for glVertexAttribPointer
		void SetAttributePointer(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer);

		/// Check documentation for glVertexAttribPointer
		void DisableAttributePointer();
	};
}