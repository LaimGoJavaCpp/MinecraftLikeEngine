#pragma once

#include "Window.h"

class InputKeyboard
{
public:
    InputKeyboard(Window* window);
    bool isKeyPressed(int button);
private:
    Window* window;
    int lastPressButton;
};