#include "VAO.h"

VAO::VAO()
{
	glGenVertexArrays(1, &vao);
	bind();
}

VAO::~VAO()
{
	glDeleteVertexArrays(1, &vao);
	glDeleteBuffers(buffers.size(), buffers.data());
}   

void VAO::bind()
{
	glBindVertexArray(vao);
}

void VAO::draw(size_t count)
{
	bind();
	for (size_t i = 0; i < buffers.size(); ++i)
	{
		glEnableVertexAttribArray(i);
	}

	glDrawArrays(GL_TRIANGLES,0,count);

	for (size_t i = 0; i < buffers.size(); ++i)
	{
		glDisableVertexAttribArray(i);
	}
}

void VAO::addVertexBufferObject(const std::vector<float>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(buffers.size(), 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	buffers.push_back(vbo);
}

void VAO::addVertexBufferObject(const std::vector<glm::vec2>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec2), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(buffers.size(), 2, GL_FLOAT, GL_FALSE, 0, nullptr);
	buffers.push_back(vbo);
}

void VAO::addVertexBufferObject(const std::vector<glm::vec3>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec3), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(buffers.size(), 3, GL_FLOAT, GL_FALSE, 0, nullptr);
	buffers.push_back(vbo);
}

void VAO::addVertexBufferObject(const std::vector<glm::vec4>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(glm::vec4), data.data(), GL_STATIC_DRAW);
	glVertexAttribPointer(buffers.size(), 4, GL_FLOAT, GL_FALSE, 0, nullptr);
	buffers.push_back(vbo);
}

void VAO::addMixedVertexBufferObject(const std::vector<float>& data)
{
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, data.size() * sizeof(float), data.data(), GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(float) * 5, nullptr);
	const uint32_t offset = sizeof(float) * 3;
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 5, reinterpret_cast<void*>(offset));
	buffers.push_back(vbo);
}