#include <iostream>

#include "graphics/window.h"    
#include "debugutils.h"
#include "input.h"

int main() 
{
    gfx::Window window;
    window.init("Core Framework", 1280, 720);
    window.setClearColor(225, 208, 130);

    // Everything contained here is for testing porpuses
    input::Keyboard &input = input::Keyboard::getInstance();

    while (!window.isClosed() && !input.isPressed(GLFW_KEY_ESCAPE))
    {
        window.pollEvents();
        window.clear();

        window.swap();

        utils::printGlErrors();
    }

    return 0;
}