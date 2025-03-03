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
}

MyGLFW::~MyGLFW()
{
	glfwTerminate();
}