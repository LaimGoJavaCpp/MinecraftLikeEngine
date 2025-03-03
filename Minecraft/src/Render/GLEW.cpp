#include "GLEW.h"
#include "Logger.h"

#include <GL/glew.h>

MyGLEW::MyGLEW()
{
	if (glewInit() != GLEW_OK) {
		Logger::log("glew is not init");
	}
	glewExperimental = true;
	Logger::log("glew init");
}