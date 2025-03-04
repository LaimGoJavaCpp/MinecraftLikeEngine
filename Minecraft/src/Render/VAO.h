#pragma once

#include <GL/glew.h>
#include <vector>
#include <glm/glm.hpp>

class VAO
{
public:
	VAO();
	~VAO();
	void bind();
	void draw(unsigned type);
	void addVertexBufferObject(const std::vector<float>& data);
	void addVertexBufferObject(const std::vector<glm::vec2>& data);
	void addVertexBufferObject(const std::vector<glm::vec3>& data);
	void addVertexBufferObject(const std::vector<glm::vec4>& data);
	void addIndices(const std::vector<unsigned>& data);
private:
	GLuint vao;
	std::vector<GLuint> buffers;
	GLuint indicesBuffer;
	size_t indicesCount = 0;
};