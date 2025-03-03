#pragma once

#include <GLFW/glfw3.h>
#include "Logger.h"

class Window
{
public:
	Window(const char* title, int width, int height);
	~Window();
	GLFWwindow* getWindow() { return window; }
	int getWidth() { return width; }
	int getHeight() { return height; }
private:
	GLFWwindow* window;
	int width;
	int height;
};