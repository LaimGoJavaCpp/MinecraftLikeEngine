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
    float aspect = static_cast<float>(window->getWidth()) / static_cast<float>(window->getHeight());
    glm::mat4 projection = glm::ortho(-aspect, aspect, -1.0f, 1.0f);

    glClearColor(0.53f, 0.81f, 0.92f, 1.0f); 
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (auto& obj : renderObjects)
    {
        obj->draw();
        glm::mat4 mvp = projection * obj->getModelMatrix();

        GLuint modelLoc = glGetUniformLocation(obj->getShader()->getProgram(), "modelMatrix");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &mvp[0][0]);
    }

    glfwSwapBuffers(window->getWindow());
    glfwPollEvents();
}