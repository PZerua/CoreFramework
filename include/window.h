/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "../input/input.h"
#include <string>

namespace gfx
{

void windowResize(GLFWwindow *window, int width, int height);

class Window
{
private:
    // Window dimensions
    int m_width;
    int m_height;

    // Window attributes
    bool m_isFullscreen;

    GLFWwindow* m_window;

public:
    // Intializes internals
    Window();
    ~Window();

    // Creates window
    bool init(const std::string &screenTitle, int window_width, int window_height, bool fullscreen = false);

    // Window dimensions
    int getWidth() const;
    int getHeight() const;

    GLFWwindow* getGlfwWindow() { return m_window; }
    bool isClosed() const;
    inline bool isFullscreen() const { return m_isFullscreen; }
    void setSize(int width, int height);
    void setClearColorNormalized(float r, float g, float b);
    void setClearColor(int r, int g, int b);
    void toggleFullscreen();

    void pollEvents();
    void swap();
    void clear() const;

};

} // namespace gfx
