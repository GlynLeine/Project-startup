#include <iostream>
#include <fstream>
#include "mge/core/rendering/ShaderProgram.hpp"
#include "mge/config.hpp"

ShaderProgram::ShaderProgram() :_programId(0), _shaderIds() {
	//why does opengl use glCreateProgram and not glGenProgram (1, &_programID)? Who knows:) *shrugs*
	_programId = glCreateProgram();
	std::cout << std::endl << "Program created with id:" << _programId << std::endl;
}

ShaderProgram::~ShaderProgram() {}

void ShaderProgram::addShader(GLuint pShaderType, const std::string &pShaderPath) {
	std::string shaderCode = _readFile(pShaderPath);
	if (shaderCode.length() <= 0)
	{
		std::cout << "File \"" << pShaderPath << "\" was found empty" << std::endl;
		return;
	}

	GLuint shaderId = _compileShader(pShaderType, shaderCode);

	if (shaderId != 0) {
		_shaderIds.push_back(shaderId);
	}
}

std::string ShaderProgram::_readFile(const std::string& pShaderPath)
{
	std::string contents;
	std::ifstream file(pShaderPath, std::ios::in);
	if (file.is_open()) {
		std::cout << "Reading shader file... " << pShaderPath << std::endl;
		std::string line = "";
		while (getline(file, line)) contents += "\n" + line;
		file.close();
	}
	else {
		std::cout << "Error reading shader " << pShaderPath << std::endl;
		contents = "";
	}
	return contents;
}

// compile the code, and detect errors.
GLuint ShaderProgram::_compileShader(GLuint pShaderType, const std::string& pShaderSource)
{
	std::cout << "Compiling shader... " << std::endl;

	std::string source = std::string(pShaderSource);

	if (pShaderType == GL_FRAGMENT_SHADER)
	{
		size_t shaderVersionIndex = source.find("#version");
		size_t shaderStartIndex = source.find("\n", shaderVersionIndex);
		std::string shaderVersion = source.substr(shaderVersionIndex, shaderStartIndex - shaderVersionIndex);
		source = shaderVersion + std::string("\n#define MAX_LIGHT_COUNT ") + std::to_string(config::MAX_LIGHT_COUNT) + std::string("\n#define PI 3.141592\n#define HALF_PI 1.570796\n") + source.substr(shaderStartIndex);
	}

	const char * sourcePointer = source.c_str();
	GLuint shaderId = glCreateShader(pShaderType);
	glShaderSource(shaderId, 1, &sourcePointer, NULL);
	glCompileShader(shaderId);

	GLint compilerResult = GL_FALSE;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compilerResult);

	if (compilerResult) {
		std::cout << "Shader compiled ok." << std::endl;
		return shaderId;
	}
	else { // get error message
		std::cout << "Shader error:" << std::endl;
		int infoLogLength;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* errorMessage = new char[infoLogLength + 1];
		glGetShaderInfoLog(shaderId, infoLogLength, NULL, errorMessage);
		std::cout << errorMessage << std::endl << std::endl;

		std::cout << std::endl << source << std::endl << std::endl;

		delete[] errorMessage;
		return 0;
	}
}

void ShaderProgram::finalize() {
	for (size_t i = 0; i < _shaderIds.size(); ++i) {
		glAttachShader(_programId, _shaderIds[i]);
	}

	glLinkProgram(_programId);

	// Check the program
	GLint linkResult = GL_FALSE;
	glGetProgramiv(_programId, GL_LINK_STATUS, &linkResult);

	if (linkResult) {
		std::cout << "Program linked ok." << std::endl << std::endl;
	}
	else { // error, show message
		std::cout << "Program error:" << std::endl;

		int infoLogLength;
		glGetProgramiv(_programId, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* errorMessage = new char[infoLogLength + 1];
		glGetProgramInfoLog(_programId, infoLogLength, NULL, errorMessage);
		std::cout << errorMessage << std::endl << std::endl;
		delete[] errorMessage;
	}

	for (size_t i = 0; i < _shaderIds.size(); ++i) {
		glDeleteShader(_shaderIds[i]);
	}
}

GLuint ShaderProgram::getUniformLocation(const std::string& pName) {
	return glGetUniformLocation(_programId, pName.c_str());
}

GLuint ShaderProgram::getAttribLocation(const std::string& pName) {
	return glGetAttribLocation(_programId, pName.c_str());
}

void ShaderProgram::use()
{
	glUseProgram(_programId);
}

void ShaderProgram::clearUsage()
{
	glUseProgram(0);
}

GLuint ShaderProgram::getUniformBlockIndex(const std::string& pName)
{
	return glGetUniformBlockIndex(_programId, pName.c_str());
}

void ShaderProgram::BindUniformBlock(GLuint uniformBlockIndex, GLuint uniformBlockBinding)
{
	glUniformBlockBinding(_programId, uniformBlockIndex, uniformBlockBinding);
}
