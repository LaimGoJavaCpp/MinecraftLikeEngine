#pragma once

#include <vector>
#include <gl/glew.h>

#include "Window.h"
#include "Camera.h"
#include "RenderObject.h"

class Render
{
public:
	Render(Window* window, Camera* camera);
	void Draw();
	void addRenderObject(RenderObject* object) { renderObjects.push_back(object); }
private:
	Window* window;
	Camera* camera;
	std::vector<RenderObject*> renderObjects;
};