#include "ldpch.h"
#include "OpenGLContext.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

namespace LazyDog
{

	OpenGLContext::OpenGLContext(GLFWwindow* windowHandle)
		: m_WindowHandle(windowHandle)
	{
		LD_CORE_ASSERT(windowHandle, "Window handle is null!")
	}

	void OpenGLContext::Init()
	{
		glfwMakeContextCurrent(m_WindowHandle);
		int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
		LD_CORE_ASSERT(status, "Failed to initialize Glad!");

		LD_CORE_INFO("OpenGL Info:");
		LD_CORE_INFO("	Vendor: \t{0}", glGetString(GL_VENDOR));
		LD_CORE_INFO("	Renderer: \t{0}", glGetString(GL_RENDERER));
		LD_CORE_INFO("	Version: \t{0}", glGetString(GL_VERSION));

	}

	void OpenGLContext::SwapBuffers()
	{
		glfwSwapBuffers(m_WindowHandle);
	}

}