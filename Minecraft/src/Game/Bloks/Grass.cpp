#include "Grass.h"

Grass::Grass()
{
    vao = new VAO();

    //vao->addVertexBufferObject(); 

    shader = new Program("block");
    shader->bindAttribute(0, "position");
    shader->bindAttribute(1, "texCoord");
    shader->link();
    shader->use();
    texture = new Texture("dirt");

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
}

void Grass::draw()
{
    texture->bind(); 
    vao->draw(GL_TRIANGLES); 
}