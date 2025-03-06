#include "GLFW.h"
#include "Logger.h"

#include <GLFW/glfw3.h>

MyGLFW::MyGLFW()
{
	if (!glfwInit()) {
		Logger::log("glfw is not init");
		std::exit(-1);
	}
	Logger::log("glfw init");
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
}

MyGLFW::~MyGLFW()
{
	glfwTerminate();
}