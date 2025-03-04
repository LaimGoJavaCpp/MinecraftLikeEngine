#include "Render.h"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

Render::Render(Window* window)
{
	this->window = window;
}

void Render::Draw()
{
	glm::mat4 modelMatrix = glm::mat4(1.0f);
	float aspect = static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight());
	glm::mat4 projection = glm::ortho(-aspect, aspect, -1.0f, 1.0f);
	glm::mat4 mvp = projection * modelMatrix;

	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	for (size_t i = 0; i < renderObjects.size(); ++i)
	{
		renderObjects.at(i)->draw();
		GLuint modelLoc = glGetUniformLocation(renderObjects.at(i)->getShader()->getProgram(), "modelMatrix");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &mvp[0][0]);
	}
	glfwSwapBuffers(window->getWindow());
	glfwPollEvents();
}