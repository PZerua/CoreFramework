/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#include "indexbuffer.h"

namespace gfx
{

    IndexBuffer::IndexBuffer(GLubyte *data, GLsizei size) :
        m_size(size)
    {
        glGenBuffers(1, &m_eboId);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_eboId);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, &data[0], GL_STATIC_DRAW);
    }

    IndexBuffer::~IndexBuffer()
    {
        glDeleteBuffers(1, &m_eboId);
    }

    void IndexBuffer::bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_eboId);
    }

    void IndexBuffer::unbind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

} // namespace gfx
