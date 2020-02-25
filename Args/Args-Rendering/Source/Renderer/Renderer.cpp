#include "Renderer/Renderer.h"
#include <sstream>

void Args::Renderer::Init()
{
	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress)))
	{
		Debug::Error(DebugInfo, "Failed to initialize OpenGL context");
		return;
	}

	BindForUpdate(std::bind(&Renderer::Render, this, std::placeholders::_1));

	std::stringstream ss;
	ss << "Initialised Renderer\n";
	ss << "\tCONTEXT INFO\n";
	ss << "\t----------------------------------\n";
	ss << "\tGPU Vendor:\t%s\n";
	ss << "\tGPU:\t\t%s\n";
	ss << "\tGL Version:\t%s\n";
	ss << "\tGLSL Version:\t%s\n";
	ss << "\t----------------------------------";

	const GLubyte* vendor = glGetString(GL_VENDOR);
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	const GLubyte* glslVersion = glGetString(GL_SHADING_LANGUAGE_VERSION);

	GLint major, minor;
	glGetIntegerv(GL_MAJOR_VERSION, &major);
	glGetIntegerv(GL_MINOR_VERSION, &minor);

	Debug::Success(DebugInfo, ss.str(), vendor, renderer, version, glslVersion);
}

void Args::Renderer::Render(float deltaTime)
{

	auto entities = GetEntityList();
	for (uint32 entity : entities)
	{

	}
}
