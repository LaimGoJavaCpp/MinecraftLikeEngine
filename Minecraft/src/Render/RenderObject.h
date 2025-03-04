#pragma once

#include "VAO.h"

class RenderObject
{
public:
	virtual void draw() = 0;
protected:
	VAO* vao;
};