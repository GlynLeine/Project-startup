#pragma once
#include <glad/glad.h>
#include <vector>
#include <string>
#include <Args-Core.h>
#include "Texture.h"

namespace Args
{
	class Mesh;
	struct Camera;
	class Shader;

	class IShaderParameter
	{
	protected:
		Shader* shader;
		std::string		name;
		GLenum			type;
		GLint			location;

		IShaderParameter(Shader* shader, std::string name, GLenum type, GLint location) : shader(shader), name(name), type(type), location(location) {};

	public:
		virtual bool IsValid() const { return location != -1; }
		virtual GLenum GetType() const { return type; }
		virtual GLint GetLocation() const { return location; }
	};

	class Sampler : public IShaderParameter
	{
	protected:
		GLint sampler;
	public:
		Sampler(Shader* shader, std::string name, GLenum type, GLint location, GLint sampler) : IShaderParameter(shader, name, type, location), sampler(sampler) {}

		void SetTexture(Texture* texture)
		{
			glActiveTexture(GL_TEXTURE0 + sampler);
			glBindTexture(GL_TEXTURE_2D, texture->GetTexture());
			glUniform1i(location, sampler);
		}
	};

	template<typename T>
	class Uniform : public IShaderParameter
	{
	public:
		Uniform(Shader* shader, std::string name, GLenum type, GLint location) : IShaderParameter(shader, name, type, location) {}

		void SetValue(const T& value)
		{
			//switch (type)
			//{
			//case GL_FLOAT:
			//	glUniform1f(location, value);
			//	break;
			//case GL_FLOAT_VEC2:
			//	glUniform2fv(location, 1, value_ptr(value));
			//	break;
			//case GL_FLOAT_VEC3:
			//	glUniform3fv(location, 1, value_ptr(value));
			//	break;
			//case GL_FLOAT_VEC4:
			//	glUniform4fv(location, 1, value_ptr(value));
			//	break;
			//case GL_INT:
			//	glUniform1i(location, value);
			//	break;
			//case GL_INT_VEC2:
			//	glUniform2iv(location, 1, value_ptr(value));
			//	break;
			//case GL_INT_VEC3:
			//	glUniform3iv(location, 1, value_ptr(value));
			//	break;
			//case GL_INT_VEC4:
			//	glUniform4iv(location, 1, value_ptr(value));
			//	break;
			//case GL_BOOL:
			//	glUniform1i(location, value);
			//	break;
			//case GL_BOOL_VEC2:
			//	glUniform2iv(location, 1, value_ptr(value));
			//	break;
			//case GL_BOOL_VEC3:
			//	glUniform3iv(location, 1, value_ptr(value));
			//	break;
			//case GL_BOOL_VEC4:
			//	glUniform4iv(location, 1, value_ptr(value));
			//	break;
			//case GL_FLOAT_MAT2:
			//	glUniformMatrix2fv(location, 1, false, value_ptr(value));
			//	break;
			//case GL_FLOAT_MAT3:
			//	glUniformMatrix3fv(location, 1, false, value_ptr(value));
			//	break;
			//case GL_FLOAT_MAT4:
			//	glUniformMatrix4fv(location, 1, false, value_ptr(value));
			//	break;
			//default:
			//	continue;
			//}
		}
	};


	class Attribute : public IShaderParameter
	{
	public:
		Attribute(Shader* shader, std::string name, GLenum type, GLint location) : IShaderParameter(shader, name, type, location) {}

		void SetAttributePointer(GLint size, GLenum type, GLboolean normalized, GLsizei stride, const GLvoid* pointer)
		{
			glVertexAttribPointer(location, size, type, normalized, stride, pointer);

			glEnableVertexAttribArray(location);
		}

		void DisableAttributePointer()
		{
			glDisableVertexAttribArray(location);
		}
	};

	class Shader
	{
	public:
		static Shader* LoadShader(const std::string& name, const std::string& vertexShader, const std::string& fragmentShader);

		void Bind(Mesh* mesh);
		void Render(const std::vector<Matrix4>& instances, Mesh* mesh, Camera* camera);
		void Release(Mesh* mesh) const;

		GLuint GetUniformBlockIndex(const std::string& pName) const;
		void BindUniformBlock(GLuint uniformBlockIndex, GLuint uniformBlockBinding) const;

		Sampler* GetSampler(const std::string& name);

		template<typename T>
		Uniform<T>* GetUniform(const std::string& name);

		
		Attribute* GetAttribute(const std::string& name);


	private:
		std::string name;

		GLint programId;
		GLuint modelMatrixBufferId;
		GLint modelMatrixAttrib;

		std::vector<GLuint> shaderIds;
		static std::unordered_map<std::string, std::unordered_map<std::string, Shader*>> shaders;

		std::unordered_map<std::string, std::unique_ptr<Sampler>> samplers;
		std::unordered_map<std::string, std::unique_ptr<IShaderParameter>> uniforms;
		std::unordered_map<std::string, std::unique_ptr<Attribute>> attributes;

		Shader(const std::string& name);

		void Finalize();

		void AddShader(GLuint pShaderType, const std::string& pShaderPath);

		std::string ReadFile(const std::string& shaderPath);

		GLuint CompileShader(GLuint shaderType, const std::string& shaderSource);

		void ProcessIncludes(std::string& shaderSource);

		void ProcessParameters();

		GLuint GetUniformLocation(const std::string& pName) const;

		GLuint GetAttribLocation(const std::string& pName) const;
	};

	template<typename T>
	inline Uniform<T>* Shader::GetUniform(const std::string& name)
	{
		return dynamic_cast<Uniform<T>*>(uniforms[name].get());
	}
}