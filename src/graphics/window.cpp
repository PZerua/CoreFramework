/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#include "Window.h"
#include <iostream>

namespace gfx
{

Window::Window() :
    m_window(nullptr),
    m_isFullscreen(false),
    m_width(0),
    m_height(0)
{}

Window::~Window()
{
    if (m_window != NULL)
    {
        glfwTerminate();
    }
}

bool Window::init(const std::string &screenTitle, int window_width, int window_height, bool fullscreen)
{
    if (!glfwInit())
    {
        std::cout << "[CORE] Failed to initialize GLFW" << std::endl;
        return false;
    }

    // Create window
    m_window = glfwCreateWindow(window_width, window_height, screenTitle.c_str(), NULL, NULL);

    if (!m_window)
    {
        std::cout << "[CORE] Window could not be created!" << std::endl;
        glfwTerminate();
        return false;
    }

    std::cout << "[CORE] Window created" << std::endl;

    m_width = window_width;
    m_height = window_height;

    // Create renderer for window
    glfwMakeContextCurrent(m_window);
    // Setup callbacks
    glfwSetKeyCallback(m_window, input::onKeyChange);
    glfwSetMouseButtonCallback(m_window, input::onMouseChange);
    glfwSetCursorPosCallback(m_window, input::onMouseMove);
    glfwSetWindowSizeCallback(m_window, windowResize);
    glfwSwapInterval(0);

    std::cout << "[CORE] OpenGL context created" << std::endl;

    glewInit();

    std::cout << "[CORE] " << glGetString(GL_VERSION) << std::endl;

    glViewport(0, 0, m_width, m_height);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glfwSetWindowUserPointer(m_window, this);

    return true;
}

void Window::clear() const
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void Window::pollEvents()
{
    glfwPollEvents();
}

void Window::swap()
{
    glfwSwapBuffers(m_window);
}

int Window::getWidth() const
{
    return m_width;
}

int Window::getHeight() const
{
    return m_height;
}

bool Window::isClosed() const
{
    return glfwWindowShouldClose(m_window) == 1;
}

void Window::setSize(int width, int height)
{
    m_width = width;
    m_height = height;
}

void Window::setClearColorNormalized(float r, float g, float b)
{
    glClearColor(r, g, b, 1.0f);
}

void Window::setClearColor(int r, int g, int b)
{
    float red, green, blue;
    red = r / 255.0f;
    green = g / 255.0f;
    blue = b / 255.0f;

    glClearColor(red, green, blue, 1.0f);
}

void Window::toggleFullscreen()
{

}

void windowResize(GLFWwindow *window, int width, int height)
{
    Window *windowClass = (Window*)glfwGetWindowUserPointer(window);
    //windowClass->setSize(width, height);
    glViewport(0, 0, width, height);
}

} // namespace gfx
