/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#include "vertexbuffer.h"

namespace gfx
{

VertexBuffer::VertexBuffer(GLvoid *data, GLsizei size, GLenum drawType)
{
    glGenBuffers(1, &m_vboId);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
    glBufferData(GL_ARRAY_BUFFER, size, data, drawType);
}

VertexBuffer::VertexBuffer()
{
    glGenBuffers(1, &m_vboId);
    glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
}

void VertexBuffer::updateData(GLvoid *data, GLsizei size, GLenum drawType)
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
    glBufferData(GL_ARRAY_BUFFER, size, data, drawType);
}

VertexBuffer::~VertexBuffer()
{
    glDeleteBuffers(1, &m_vboId);
}

void VertexBuffer::bind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, m_vboId);
}

void VertexBuffer::unbind() const
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}

} // namespace gfx
