#pragma once

#include "VAO.h"
#include "Program.h"

class RenderObject
{
public:
	virtual void draw() = 0;
	Program* getShader() { return shader; }
protected:
	Program* shader;
	VAO* vao;
};