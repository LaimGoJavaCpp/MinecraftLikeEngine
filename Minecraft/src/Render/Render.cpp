#include "Render.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

Render::Render(Window* window, Camera* camera)
{
    this->window = window;
    this->camera = camera;
}

void Render::Draw()
{
    glClearColor(0.53f, 0.81f, 0.92f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glm::mat4 view = camera->getViewMatrix();
    glm::mat4 projection = glm::perspective(glm::radians(45.0f),
        (float)window->getWidth() / (float)window->getHeight(),
        0.1f, 100.0f);

    for (size_t i = 0; i < renderObjects.size(); ++i)
    {
        glm::mat4 model = renderObjects.at(i)->getModelMatrix(); 
        glm::mat4 mvp = projection * view * model;  

        GLuint mvpLoc = glGetUniformLocation(renderObjects.at(i)->getShader()->getProgram(), "MVP");
        if (mvpLoc != -1) {
            glUniformMatrix4fv(mvpLoc, 1, GL_FALSE, &mvp[0][0]);
        }

        renderObjects.at(i)->draw();
    }

    glfwSwapBuffers(window->getWindow());
    glfwPollEvents();
}