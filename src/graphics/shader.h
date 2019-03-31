/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include "../utils/fileutils.h"
#include "../math/vec2.h"
#include "../math/vec3.h"
#include "../math/vec4.h"
#include "../math/mat4.h"
#include <GL/glew.h>
#include "texturearray.h"

namespace gfx
{

#define GN_PROJECTION_UNIFORM_LOCATION 0

class Shader
{
private:
    // Program ID
    GLuint m_programId;

public:
    // Builds the shader
    Shader(const std::string &shaderName);
    ~Shader();

    // Get program ID
    inline GLuint getId() const { return m_programId; }

    // Activate the shader
    static void enable(GLuint programId);
    static void disable(GLuint programId);
    // Utility uniform functions
    static void setBool(GLuint programId, const char* name, bool value);
    static void setInt(GLuint programId, const char* name, int value);
    static void setFloat(GLuint programId, const char* name, float value);
    static void setVector2(GLuint programId, const char* name, const math::vec2 &vec);
    static void setVector3(GLuint programId, const char* name, const math::vec3 &vec);
    static void setVector4(GLuint programId, const char* name, const math::vec4 &vec);
    static void setMatrix4(GLuint programId, const char* name, const math::mat4 &mat);

private:
    // Utility functions
    void compileShader(GLuint &shader, GLenum shaderType, const char *shaderCode);
    void printShaderErrors(GLuint shader) const;
    void printProgramErrors(GLuint shader) const;
};

} // namespace gfx
