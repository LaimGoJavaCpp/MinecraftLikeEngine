#include "Window.h"

Window::Window(const char* title)
{
	const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());
	width = mode->width;
	height = mode->height;
	
	window = glfwCreateWindow(mode->width, mode->height, "Minecraft", glfwGetPrimaryMonitor(), nullptr);
	if (!window) {
		Logger::log("Window not init!");
		std::exit(-1);
	}
	glfwMakeContextCurrent(window);
	glViewport(0,0, mode->width,mode->height);
	Logger::log("window init");
}

Window::~Window()
{
	glfwDestroyWindow(window);
}