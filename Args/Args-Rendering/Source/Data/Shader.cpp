#include "Data/Shader.h"
#include "Data/Mesh.h"
#include "Components/Camera.h"
#include <fstream>

const unsigned MAX_LIGHT_COUNT = 100; // <-- Move to config file
const size_t MAX_VBO_SIZE = 1048576; // 1MB <-- Move to config file


Args::Shader::Shader(const std::string& name) : programId(0), shaderIds(), name(name), modelMatrixAttrib(-1), modelMatrixBufferId(-1)
{
	programId = glCreateProgram();
	Debug::Log(DebugInfo, "Program created with id: %i", programId);
}

Args::Shader::~Shader() {}

void Args::Shader::AddShader(GLuint pShaderType, const std::string& pShaderPath)
{
	std::string shaderCode = readFile(pShaderPath);
	if (shaderCode.length() <= 0)
	{
		Debug::Error(DebugInfo, "File \"%s\" was found empty", pShaderPath.c_str());
		return;
	}

	GLuint shaderId = compileShader(pShaderType, shaderCode);

	if (shaderId != 0)
		shaderIds.push_back(shaderId);
}

std::string Args::Shader::readFile(const std::string& pShaderPath)
{
	std::string contents;
	std::ifstream file(pShaderPath, std::ios::in);
	if (file.is_open())
	{
		Debug::Log(DebugInfo, "Reading shader file... %s", pShaderPath.c_str());
		std::string line = "";
		while (getline(file, line)) contents += "\n" + line;
		file.close();
	}
	else
	{
		Debug::Error(DebugInfo, "Error reading shader %s", pShaderPath.c_str());
		contents = "";
	}
	return contents;
}

// compile the code, and detect errors.
GLuint Args::Shader::compileShader(GLuint pShaderType, const std::string& pShaderSource)
{
	std::string shadertype = "unknown";

	switch (pShaderType)
	{
	case GL_FRAGMENT_SHADER:
		shadertype = "fragment";
		break;
	case GL_VERTEX_SHADER:
		shadertype = "vertex";
		break;
	default:
		break;
	}

	Debug::Log(DebugInfo, "Compiling %s %s shader... ", name.c_str(), shadertype.c_str());

	std::string source = std::string(pShaderSource);

	if (pShaderType == GL_FRAGMENT_SHADER)
	{
		size_t shaderVersionIndex = source.find("#version");
		size_t shaderStartIndex = source.find("\n", shaderVersionIndex);
		std::string shaderVersion = source.substr(shaderVersionIndex, shaderStartIndex - shaderVersionIndex);
		source = shaderVersion + std::string("\n#define MAX_LIGHT_COUNT ") + std::to_string(MAX_LIGHT_COUNT) + std::string("\n#define PI 3.141592\n#define HALF_PI 1.570796\n") + source.substr(shaderStartIndex);
	}

	const char* sourcePointer = source.c_str();
	GLuint shaderId = glCreateShader(pShaderType);
	glShaderSource(shaderId, 1, &sourcePointer, nullptr);
	glCompileShader(shaderId);

	GLint compilerResult = GL_FALSE;
	glGetShaderiv(shaderId, GL_COMPILE_STATUS, &compilerResult);

	if (compilerResult)
	{
		Debug::Success(DebugInfo, "Compiled %s %s shader successfully.", name.c_str(), shadertype.c_str());
		return shaderId;
	}
	else { // get error message
		int infoLogLength;
		glGetShaderiv(shaderId, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* errorMessage = new char[infoLogLength + 1];
		glGetShaderInfoLog(shaderId, infoLogLength, nullptr, errorMessage);

		Debug::Error(DebugInfo, "Shader error in %s %s shader:\n\t%s", name.c_str(), shadertype.c_str(), errorMessage);
		delete[] errorMessage;
		return 0;
	}
}

void Args::Shader::Finalize()
{
	for (size_t i = 0; i < shaderIds.size(); ++i)
		glAttachShader(programId, shaderIds[i]);

	glLinkProgram(programId);

	// Check the program
	GLint linkResult = GL_FALSE;
	glGetProgramiv(programId, GL_LINK_STATUS, &linkResult);

	if (linkResult)
		Debug::Success(DebugInfo, "Program %s linked successfully.", name.c_str());
	else
	{ // error, show message
		int infoLogLength;
		glGetProgramiv(programId, GL_INFO_LOG_LENGTH, &infoLogLength);
		char* errorMessage = new char[infoLogLength + 1];
		glGetProgramInfoLog(programId, infoLogLength, nullptr, errorMessage);

		Debug::Error(DebugInfo, "Program error in %s:\n\t%s", name.c_str(), errorMessage);

		delete[] errorMessage;
	}

	for (size_t i = 0; i < shaderIds.size(); ++i)
		glDeleteShader(shaderIds[i]);

	modelMatrixAttrib = GetAttribLocation("modelMatrix");

	if (modelMatrixAttrib != -1)
	{
		glGenBuffers(1, &modelMatrixBufferId);
		glBindBuffer(GL_ARRAY_BUFFER, modelMatrixBufferId);
		glBufferData(GL_ARRAY_BUFFER, MAX_VBO_SIZE, nullptr, GL_DYNAMIC_DRAW);
		glBindBuffer(GL_ARRAY_BUFFER, 0);
	}
	else
		Debug::Warning(DebugInfo, "Shader %s does not contain attribute \"modelMatrix\"\nNo instancing enabled on this shader", name.c_str());
}

GLuint Args::Shader::GetUniformLocation(const std::string& pName)
{
	return glGetUniformLocation(programId, pName.c_str());
}

GLuint Args::Shader::GetAttribLocation(const std::string& pName)
{
	return glGetAttribLocation(programId, pName.c_str());
}

void Args::Shader::Bind(Mesh* mesh)
{
	glUseProgram(programId);
	mesh->Bind(vertexAttrib, normalAttrib, uvAttrib, tangentAttrib);
}

void Args::Shader::Render(std::vector<Matrix4>& instances, Mesh* mesh, Camera* camera)
{
	if (modelMatrixAttrib != -1)
	{
		glBindBuffer(GL_ARRAY_BUFFER, modelMatrixBufferId);

		glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Matrix4) * instances.size(), &(instances.data()[0]));

		glEnableVertexAttribArray(modelMatrixAttrib + 0);
		glEnableVertexAttribArray(modelMatrixAttrib + 1);
		glEnableVertexAttribArray(modelMatrixAttrib + 2);
		glEnableVertexAttribArray(modelMatrixAttrib + 3);

		glVertexAttribPointer(modelMatrixAttrib + 0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(Vector4), (GLvoid*)0);
		glVertexAttribPointer(modelMatrixAttrib + 1, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(Vector4), (GLvoid*)(sizeof(Vector4)));
		glVertexAttribPointer(modelMatrixAttrib + 2, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(Vector4), (GLvoid*)(2 * sizeof(Vector4)));
		glVertexAttribPointer(modelMatrixAttrib + 3, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(Vector4), (GLvoid*)(3 * sizeof(Vector4)));

		glVertexAttribDivisor(modelMatrixAttrib + 0, 1);
		glVertexAttribDivisor(modelMatrixAttrib + 1, 1);
		glVertexAttribDivisor(modelMatrixAttrib + 2, 1);
		glVertexAttribDivisor(modelMatrixAttrib + 3, 1);
	}

	glUniform3fv(cameraPositionUniform, 1, value_ptr(camera->GetPosition()));
	glUniformMatrix4fv(viewProjectionMatrixUniform, 1, GL_FALSE, value_ptr(camera->GetViewProjection()));

	mesh->Draw(instances.size());

	if (modelMatrixAttrib != -1)
	{
		glBindBuffer(GL_ARRAY_BUFFER, 0);
		glDisableVertexAttribArray(modelMatrixAttrib + 0);
		glDisableVertexAttribArray(modelMatrixAttrib + 1);
		glDisableVertexAttribArray(modelMatrixAttrib + 2);
		glDisableVertexAttribArray(modelMatrixAttrib + 3);
	}
}

void Args::Shader::Release(Mesh* mesh)
{
	glUseProgram(0);
}

GLuint Args::Shader::GetUniformBlockIndex(const std::string& pName)
{
	return glGetUniformBlockIndex(programId, pName.c_str());
}

void Args::Shader::BindUniformBlock(GLuint uniformBlockIndex, GLuint uniformBlockBinding)
{
	glUniformBlockBinding(programId, uniformBlockIndex, uniformBlockBinding);
}
