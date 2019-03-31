/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include <GL/glew.h>

namespace gfx
{

    class IndexBuffer
    {
    private:
        GLuint m_eboId;
        GLsizei m_size;

    public:

        IndexBuffer(GLubyte *data, GLsizei size);
        ~IndexBuffer();

        void bind() const;
        void unbind() const;
    };

} // namespace gfx
