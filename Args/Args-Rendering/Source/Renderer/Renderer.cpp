#include "Renderer/Renderer.h"
#include "Components/Camera.h"
#include "Args-Window.h"
#include <sstream>

void Args::Renderer::Init()
{
	if (!gladLoadGLLoader(GLADloadproc(glfwGetProcAddress)))
	{
		Debug::Error(DebugInfo, "Failed to initialize OpenGL context");
		return;
	}

	BindForUpdate(std::bind(&Renderer::Render, this, std::placeholders::_1));

	glEnable(GL_DEBUG_OUTPUT);
	glDebugMessageCallback((GLDEBUGPROC)Renderer::ErrorCallback, 0);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_DEPTH_TEST);
	glDepthMask(GL_TRUE);
	glDepthFunc(GL_LEQUAL);
	glEnable(GL_CULL_FACE);

	IVector2 viewportSize = GetStaticComponent<Window>()->GetFramebufferSize();
	glViewport(0, 0, viewportSize.x, viewportSize.y);

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
	cpuClock.Start();
}

void Args::Renderer::Render(float deltaTime)
{
	float cpuTime = cpuClock.End().Milliseconds();
	Debug::Log(DebugInfo, "CPU time: %fms", cpuTime);
	Clock gpuClock;
	gpuClock.Start();

	glClearColor(1.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);

	std::unordered_map<Mesh*, std::unordered_map<Material*, std::vector<Renderable*>>> batches;

	auto entities = GetEntityList();
	for (uint32 entityId : entities)
	{
		Renderable* renderable = GetComponent<Renderable>(entityId);
		batches[renderable->mesh][renderable->material].push_back(renderable);
	}


	Camera* camera = GetComponentsOfType<Camera>()[0];

	for (auto& batch : batches)
	{
		if (!batch.first)
			continue;

		Mesh* mesh = batch.first;
		for (auto& materialGroup : batch.second)
		{
			Material* material;

			if (materialGroup.first == nullptr)
				continue;
			else
				material = materialGroup.first;

			material->Bind(mesh);

			std::vector<Matrix4> modelMatrices = std::vector<Matrix4>();
			for (Renderable* instance : materialGroup.second)
			{
				modelMatrices.push_back(instance->owner->GetComponent<Transform>()->GetWorldTransform());
			}

			material->Render(modelMatrices, mesh, camera);
			material->Release(mesh);
		}
	}

	GetStaticComponent<Window>()->Display();

	float gpuTime = gpuClock.End().Milliseconds();
	Debug::Log(DebugInfo, "GPU time: %fms", gpuTime);
	Debug::Log(DebugInfo, "Combined time: %fms", cpuTime + gpuTime);
	cpuClock.Start();
}

void Args::Renderer::ErrorCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	if (severity != GL_DEBUG_SEVERITY_NOTIFICATION)
	{
		try
		{
			Debug::Error(DebugInfo, "GL CALLBACK: %s type = 0x%x, severity = 0x%x, message = %s", (type == GL_DEBUG_TYPE_ERROR ? " GL ERROR " : ""), type, severity, message);
		}
		catch (std::logic_error e)
		{

		}
	}
}
