#pragma once

#include <gl/glew.h>
#include <string>

class Program
{
public:
	Program(std::string name);
	~Program();
	void link();
	void use();
	void bindAttribute(GLuint index, const std::string& name);
private:
	GLuint program;
	GLuint vertShader;
	GLuint fragShader;
	GLuint loadShader(const std::string& path, GLenum shaderType);
};