/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include <string>

#define STBI_ONLY_PNG

#include <stb_image.h>
#include <GL/glew.h>

namespace gfx
{

class TextureBase
{

protected:
    GLuint m_textureId;
    GLuint m_width;
    GLuint m_height;

public:
    virtual void bind() const = 0;
    virtual void unbind() const = 0;

    inline GLuint getId() const { return m_textureId; }
    inline GLuint getWidth() const { return m_width; }
    inline GLenum getHeight() const { return m_height; }

protected:
    TextureBase() : m_width(0), m_height(0) {}
    TextureBase(GLuint width, GLuint height) : m_width(width), m_height(height) {}

    struct TexInfo
    {
        GLint width;
        GLint height;
        GLint bpp;
        GLubyte* data;
    };

    TexInfo* loadTEX(const char *texturePath);
};

} // namespace gfx
