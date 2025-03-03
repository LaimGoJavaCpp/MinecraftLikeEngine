#pragma once

#include <GL/glew.h>
#include <vector>

class VAO
{
public:
	VAO();
	~VAO();
	void bind();
	void draw(GLsizei count);
	void addVertexBufferObject(const std::vector<float>& data);
private:
	GLuint vao;
	std::vector<GLuint> buffers;
};