#include "Grass.h"

Grass::Grass()
{
	vao = new VAO();
	vao->addVertexBufferObject({
	0.0f,  0.5f, 0.0f,
	-0.5f, -0.5f, 0.0f,
	 0.5f, -0.5f, 0.0f,
	});

	vao->addVertexBufferObject({
		{1.0f, 0.0f, 0.f, },
		{ 0.0f, 1.0f, 0.0f, },
		{ 0.0f, 0.0f, 1.0f }
	});
	shader = new Program("first");
	shader->bindAttribute(0, "position");
	shader->bindAttribute(1, "color");
	shader->link();
	shader->use();
	anim = 0;
}

void Grass::draw()
{
	anim += 0.001f;
	shader->setFloat("animation", glm::sin(anim) * 0.5f + 0.5f);
	vao->draw(3);
}