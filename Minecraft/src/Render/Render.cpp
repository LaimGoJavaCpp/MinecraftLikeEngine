#include "Render.h"

#include <glm/glm.hpp>

using namespace glm;

Render::Render(Window* window)
{
	this->window = window;
}

void Render::Draw()
{
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	for (size_t i = 0; i < renderObjects.size(); ++i)
	{
		renderObjects.at(i)->draw();
	}
	glfwSwapBuffers(window->getWindow());
	glfwPollEvents();
}