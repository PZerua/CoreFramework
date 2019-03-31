/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include <vector>
#include <memory>

#include <GL/glew.h>

namespace gfx
{

#define ATTRIBUTE_VERTEX 0
#define ATTRIBUTE_COLOR 1
#define ATTRIBUTE_MODELMATRIX 2
#define ATTRIBUTE_TEXTUREINDICES 6

class VertexArray
{
private:
    GLuint m_vaoId;

public:
    VertexArray();
    ~VertexArray();

    void bind() const;
    void unbind() const;
};

} // namespace gfx
