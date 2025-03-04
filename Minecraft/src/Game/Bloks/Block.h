#pragma once

#include "RenderObject.h" 
#include "Program.h"
#include "Texture.h"

class Block : public RenderObject
{
protected:
	Program* shader;
	Texture* texture;
};