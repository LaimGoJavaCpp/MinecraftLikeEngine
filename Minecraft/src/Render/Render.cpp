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

    static float angle = 0.0f;
    angle += 0.01f; 
    glm::mat4 rotationMatrix = glm::rotate(modelMatrix, glm::radians(angle), glm::vec3(0.0f, 1.0f, 0.0f));


    glm::mat4 mvp = projection * rotationMatrix;

    glClearColor(0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    for (size_t i = 0; i < renderObjects.size(); ++i)
    {
        renderObjects.at(i)->draw();
        GLuint modelLoc = glGetUniformLocation(renderObjects.at(i)->getShader()->getProgram(), "modelMatrix");
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, &mvp[0][0]); 
    }

    glfwSwapBuffers(window->getWindow());
    glfwPollEvents();
}