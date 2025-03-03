#pragma once

#include "GLFW.h"
#include "Window.h"
#include "GLEW.h"

#include <string>

using namespace std;

class Game
{
public:
	Game();
	void Work();
private:
	MyGLFW* glfw;
	Window* window;
	MyGLEW* glew;

	string version;
	string gameAuthors[1];
};