/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once
#include <GLFW/glfw3.h>

namespace input 
{
    // Callbacks definition
    void onKeyChange(GLFWwindow* window, int key, int scancode, int action, int mods);
    void onMouseMove(GLFWwindow* window, double mx, double my);
    void onMouseChange(GLFWwindow* window, int button, int action, int mods);

class Mouse
{
public:
    static Mouse& getInstance();

    inline double getX() const { return m_mx; }
    inline double getY() const { return m_my; }

    inline void setX(double x) { m_mx = x; }
    inline void setY(double y) { m_my = y; }

    inline void setButtonState(unsigned int button, bool state)
    {
        m_buttons[button] = state;
    }

    inline bool isPressed(unsigned int button) const
    {
        return m_buttons[button];
    }

private:
    Mouse()
    {
        for (int i = 0; i < GLFW_MOUSE_BUTTON_LAST; ++i)
            m_buttons[i] = false;
    }

private:
    static Mouse m_instance;

    // Current state of the mouse
    bool   m_buttons[GLFW_MOUSE_BUTTON_LAST];
    double m_mx;
    double m_my;
};

class Keyboard
{
public:
    static Keyboard& getInstance();

    inline void setKeyState(unsigned int key, bool state)
    {
        m_keys[key] = state;
    }

    inline bool isPressed(unsigned int key) const
    {
        return m_keys[key];
    }

private:
    Keyboard()
    {
        for (int i = 0; i < GLFW_KEY_LAST; ++i)
            m_keys[i] = false;
    }

private:
    static Keyboard m_instance;

    // Current state of the keyboard
    bool m_keys[GLFW_KEY_LAST];
};

} // namespace input