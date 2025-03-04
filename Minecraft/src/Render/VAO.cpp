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
	glDeleteBuffers(1, &indicesBuffer);
}   

void VAO::bind()
{
	glBindVertexArray(vao);
}

void VAO::draw(unsigned type = 0x0004)
{
	bind();
	for (size_t i = 0; i < buffers.size(); ++i)
	{
		glEnableVertexAttribArray(i);
	}

	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
	glDrawElements(type, indicesCount, GL_UNSIGNED_INT, nullptr);

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

void VAO::addIndices(const std::vector<unsigned>& data)
{
	indicesCount = data.size();

	glGenBuffers(1, &indicesBuffer);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indicesBuffer);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, data.size() * sizeof(unsigned), data.data(), GL_STATIC_DRAW);
}