#pragma once
#include <Args-Core.h>
#include <GLFW/glfw3.h>
#include <unordered_map>
#include <typeindex>
#include <functional>

namespace Args
{
	struct Window : public GlobalComponent<Window>
	{
		GLFWwindow* handle;

		void Create(int width, int height, const char* title, GLFWmonitor* monitor = nullptr, GLFWwindow* share = nullptr)
		{
			handle = glfwCreateWindow(width, height, title, monitor, share);
		}

		operator GLFWwindow* () const { return handle; }

		std::unordered_map < std::type_index, std::function<void(int, int)> >sah;

		// Inherited via GlobalComponent
		virtual std::string ObjectType() override;
		virtual bool SetData(const std::string& name, const std::string& value) override;
		virtual bool GetData(const std::string& name, std::string& value) override;
	};
}