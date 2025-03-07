#pragma once

#include "VAO.h"
#include "Program.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class RenderObject
{
public:
    RenderObject()
        : position(0.0f),
        rotation(0.0f),
        scale(1.0f),
        modelMatrix(1.0f)
    {}

    virtual void draw() = 0;
    Program* getShader() { return shader; }

    void setPosition(const glm::vec3& pos) { position = pos; updateModelMatrix(); }
    void setRotation(float angle) { rotation = angle; updateModelMatrix(); }
    void setScale(const glm::vec3& s) { scale = s; updateModelMatrix(); }

    glm::mat4 getModelMatrix() const { return modelMatrix; }

protected:
    Program* shader;
    VAO* vao;
    glm::vec3 position;
    float rotation;
    glm::vec3 scale;
    glm::mat4 modelMatrix;

    void updateModelMatrix()
    {
        modelMatrix = glm::mat4(1.0f);
        modelMatrix = glm::translate(modelMatrix, position);
        modelMatrix = glm::rotate(modelMatrix, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f)); 
        modelMatrix = glm::scale(modelMatrix, scale);
    }
};