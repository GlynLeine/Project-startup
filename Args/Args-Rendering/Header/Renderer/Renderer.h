#pragma once
#include <Args-Core.h>
#include "Components/Renderable.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Args
{
	class Renderer : public MonoUpdateSystem<Renderer, Renderable, Transform>
	{
		Clock cpuClock;

		virtual void Init() override;

		void Render(float deltaTime);

		static void ErrorCallback(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam);

	};
}