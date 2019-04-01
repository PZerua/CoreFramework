/**
* (c) 2017 Pablo Luis Garc�a. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#include "debugutils.h"
#include <iostream>

namespace utils
{

void printGlErrors()
{
    GLenum err;
    while ((err = glGetError()) != GL_NO_ERROR)
    {
        switch (err)
        {
        case GL_NO_ERROR:
            std::cout << "GL_NO_ERROR" << std::endl;
            break;
        case GL_INVALID_ENUM:
            std::cout << "GL_INVALID_ENUM" << std::endl;
            break;
        case GL_INVALID_VALUE:
            std::cout << "GL_INVALID_VALUE" << std::endl;
            break;
        case GL_INVALID_OPERATION:
            std::cout << "GL_INVALID_OPERATION" << std::endl;
            break;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            std::cout << "GL_INVALID_FRAMEBUFFER_OPERATION" << std::endl;
            break;
        case GL_OUT_OF_MEMORY:
            std::cout << "GL_OUT_OF_MEMORY" << std::endl;
            break;
        }
    }
}

} // namespace utils
