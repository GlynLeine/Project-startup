#pragma once
#include <Args-Core.h>
#include "Components/Renderable.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Args
{
	class Renderer : public System<Renderer, Renderable>
	{
		virtual void Init() override;
	};
}