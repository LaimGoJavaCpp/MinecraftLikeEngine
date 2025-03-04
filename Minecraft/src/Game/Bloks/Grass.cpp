#include "Grass.h"

Grass::Grass()
{
    vao = new VAO();

    std::vector<glm::vec3> vertices = {
        {-0.5f, -0.5f, -0.5f},  
        { 0.5f, -0.5f, -0.5f},  
        { 0.5f,  0.5f, -0.5f},  
        {-0.5f,  0.5f, -0.5f},  
        {-0.5f, -0.5f,  0.5f},  
        { 0.5f, -0.5f,  0.5f},  
        { 0.5f,  0.5f,  0.5f}, 
        {-0.5f,  0.5f,  0.5f},  
    };

    std::vector<glm::vec2> texCoords = {
        {0.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f}, 
        {0.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f}, 
        {0.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f}, 
        {0.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f}, 
        {0.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f},
        {0.0f, 1.0f}, {1.0f, 1.0f}, {1.0f, 0.0f}, {0.0f, 0.0f},
    };

    std::vector<unsigned> indices = {
        0, 1, 2, 0, 2, 3, 
        4, 5, 6, 4, 6, 7, 
        0, 3, 7, 0, 7, 4, 
        1, 2, 6, 1, 6, 5, 
        3, 2, 6, 3, 6, 7, 
        0, 1, 5, 0, 5, 4  
    };

    vao->addVertexBufferObject(vertices);
    vao->addVertexBufferObject(texCoords); 
    vao->addIndices(indices); 

    shader = new Program("block");
    shader->bindAttribute(0, "position");
    shader->bindAttribute(1, "texCoord");
    shader->link();
    shader->use();
    texture = new Texture("dirt");
}

void Grass::draw()
{
    texture->bind(); 
    vao->draw(GL_TRIANGLES); 
}