/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#include "uniformbuffer.h"

#include <iostream>

namespace gfx
{

UniformBuffer::UniformBuffer(GLvoid *data, GLsizei size, GLenum drawType)
{
    glGenBuffers(1, &m_uboId);
    glBindBuffer(GL_UNIFORM_BUFFER, m_uboId);
    glBufferData(GL_UNIFORM_BUFFER, size, data, drawType);
}

UniformBuffer::~UniformBuffer()
{
    glDeleteBuffers(1, &m_uboId);
}

void UniformBuffer::bindToShader(GLuint programId, const char *blockName, GLuint bindingPointIndex)
{
    GLuint blockIndex = glGetUniformBlockIndex(programId, blockName);

    glBindBufferBase(GL_UNIFORM_BUFFER, bindingPointIndex, m_uboId);
    glUniformBlockBinding(programId, blockIndex, bindingPointIndex);
}

void UniformBuffer::updateData(GLvoid *data, GLsizei size)
{
    glBindBuffer(GL_UNIFORM_BUFFER, m_uboId);
    GLvoid *gpuData = glMapBuffer(GL_UNIFORM_BUFFER, GL_WRITE_ONLY);
    std::memcpy(gpuData, data, size);
    glUnmapBuffer(GL_UNIFORM_BUFFER);
}

void UniformBuffer::bind() const
{
    glBindBuffer(GL_UNIFORM_BUFFER, m_uboId);
}

void UniformBuffer::unbind() const
{
    glBindBuffer(GL_UNIFORM_BUFFER, 0);
}

} // namespace gfx
