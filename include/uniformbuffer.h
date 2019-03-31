/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include <GL/glew.h>

namespace gfx
{
    
class UniformBuffer
{
private:
    GLuint m_uboId;

public:

    UniformBuffer(GLvoid *data, GLsizei size, GLenum drawType = GL_DYNAMIC_DRAW);
    ~UniformBuffer();

    inline GLuint getId() const { return m_uboId; };

    void bind() const;
    void unbind() const;

    void bindToShader(GLuint programId, const char *blockName, GLuint bindingPointIndex);
    void updateData(GLvoid *data, GLsizei size);
};

} // namespace gfx
