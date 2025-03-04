#pragma once

#include <gl/glew.h>
#include <string>

class Texture
{
public:
	Texture(const std::string& name);
	~Texture();
	void bind();
private:
	GLuint loadTexture(const std::string& path);
	GLuint texture;
};