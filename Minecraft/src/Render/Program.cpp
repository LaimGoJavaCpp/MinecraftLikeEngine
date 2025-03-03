#include "Program.h"

#include <fstream>
#include <iterator>
#include "Logger.h"

Program::Program(std::string name)
{
	program = glCreateProgram();
	vertShader = loadShader("res/shaders/" + name + ".vert", GL_VERTEX_SHADER);
	fragShader = loadShader("res/shaders/" + name + ".frag", GL_FRAGMENT_SHADER);
}

Program::~Program()
{
	glDeleteProgram(program);
}

void Program::link()
{
	glAttachShader(program, vertShader);
	glAttachShader(program, fragShader);
	glLinkProgram(program);
}

void Program::use()
{
	glUseProgram(program);
}

void Program::bindAttribute(GLuint index, const std::string& name)
{
	glBindAttribLocation(program, index, name.c_str());
}

GLuint Program::loadShader(const std::string& path, GLenum shaderType)
{
	GLuint shader = glCreateShader(shaderType);
	std::ifstream fis(path);
	std::string shaderCode = { std::istreambuf_iterator<char>(fis), std::istreambuf_iterator<char>() };
	const char* c = shaderCode.c_str();
	glShaderSource(shader, 1, &c, nullptr);
	glCompileShader(shader);
	GLint status;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &status);
	char buf[0x1000];
	GLsizei len;
	glGetShaderInfoLog(shader, sizeof(buf), &len, buf);
	if (len > 0)
	{
		std::cout << path << ":" << std::endl << buf;
	}
	return shader;
}
