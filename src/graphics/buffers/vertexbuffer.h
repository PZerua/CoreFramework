/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include <GL/glew.h>

namespace gfx
{

class VertexBuffer
{
private:
    GLuint m_vboId;

public:

    VertexBuffer(GLvoid *data, GLsizei size, GLenum drawType = GL_STATIC_DRAW);
    VertexBuffer();
    ~VertexBuffer();

    inline GLuint getId() const { return m_vboId; };

    void bind() const;
    void unbind() const;

    void updateData(GLvoid *data, GLsizei size, GLenum drawType = GL_STREAM_DRAW);
};

} // namespace gfx
