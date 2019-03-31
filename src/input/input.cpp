/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#include "input.h"

namespace input 
{

// Setup the mouse singleton.
Mouse Mouse::m_instance;

Mouse& Mouse::getInstance()
{
    return Mouse::m_instance;
}

// Setup the keyboard singleton.
Keyboard Keyboard::m_instance;

Keyboard& Keyboard::getInstance()
{
    return Keyboard::m_instance;
}

// Input callback functions
void onKeyChange(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    Keyboard::getInstance().setKeyState(key, action != GLFW_RELEASE);
}

void onMouseMove(GLFWwindow* window, double mx, double my)
{
    Mouse& mouse = input::Mouse::getInstance();

    mouse.setX(mx);
    mouse.setY(my);
}

void onMouseChange(GLFWwindow* window, int button, int action, int mods)
{
    Mouse::getInstance().setButtonState(button, action != GLFW_RELEASE);
}

} // namespace input
