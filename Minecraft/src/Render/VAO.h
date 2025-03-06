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
	void draw(size_t count);
	void addVertexBufferObject(const std::vector<float>& data);
	void addVertexBufferObject(const std::vector<glm::vec2>& data);
	void addVertexBufferObject(const std::vector<glm::vec3>& data);
	void addVertexBufferObject(const std::vector<glm::vec4>& data);
	void addMixedVertexBufferObject(const std::vector<float>& data);
private:
	GLuint vao;
	std::vector<GLuint> buffers;
};