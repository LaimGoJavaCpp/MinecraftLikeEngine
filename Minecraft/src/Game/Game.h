#pragma once

#include "Render.h"
#include "GLFW.h"
#include "Window.h"
#include "GLEW.h"
#include "Camera.h"
#include "InputKeyboard.h"

#include <string>

using namespace std;

class Game
{
public:
    Game();
    void Work();
private:
    void InputKeyBoardProcces();

    MyGLFW* glfw;
    Window* window;
    MyGLEW* glew;
    Render* render;
    Camera* camera;
    InputKeyboard* keyboard;

    string version;
    string gameAuthors[1];
    float lastFrame = 0.0f;
};