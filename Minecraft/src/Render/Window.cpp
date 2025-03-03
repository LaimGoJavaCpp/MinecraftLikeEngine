#include "Window.h"

Window::Window(const char* title, int width, int height)
{
	this->width = width;
	this->height = height;
	window = glfwCreateWindow(this->width, this->height,title,NULL,NULL);
	if (!window) {
		Logger::log("Window not init!");
		std::exit(-1);
	}
	glfwMakeContextCurrent(window);
	Logger::log("window init");
}

Window::~Window()
{
	glfwDestroyWindow(window);
}