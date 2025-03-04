#include "Grass.h"

Grass::Grass()
{
	vao = new VAO();
	vao->addVertexBufferObject({
		{-0.5f,0.5f,0.0f},
		{-0.5f,-0.5f, 0.0f},
		{0.5f,0.5f, 0.0f},

		{ 0.5f,0.5f,0.0f },
		{-0.5f,-0.5f, 0.0f},
		{0.5f,-0.5f, 0.0f},
	});

	vao->addVertexBufferObject({
		{0.0f, 1.0f}, 
		{0.0f, 0.0f}, 
		{1.0f, 1.0f}, 

		{1.0f, 1.0f}, 
		{0.0f, 0.0f}, 
		{1.0f, 0.0f} 
	});


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
	vao->draw(6);
}