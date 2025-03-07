#include "InputKeyboard.h"
#include <GLFW/glfw3.h>

InputKeyboard::InputKeyboard(Window* window)
{
    this->window = window;
    lastPressButton = 0;
}

bool InputKeyboard::isKeyPressed(int button)
{
    if (glfwGetKey(window->getWindow(), button) == GLFW_PRESS)
    {
        return true;
    }
    return false;
}