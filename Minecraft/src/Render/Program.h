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
	void setFloat(const std::string& name, float value);
	GLuint getLocation(const std::string& name);
	GLuint getProgram() { return program; }
private:
	GLuint program;
	GLuint vertShader;
	GLuint fragShader;
	GLuint loadShader(const std::string& path, GLenum shaderType);
};