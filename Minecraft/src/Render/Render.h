#pragma once

#include <gl/glew.h>
#include "Window.h"
#include <vector>
#include "RenderObject.h"

class Render
{
public:
	Render(Window* window);
	void Draw();
	void addRenderObject(RenderObject* object) { renderObjects.push_back(object); }
private:
	Window* window;
	std::vector<RenderObject*> renderObjects;
};