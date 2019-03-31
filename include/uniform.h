/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include "shader.h"
#include "../math/vec2.h"
#include "../math/vec3.h"
#include "../math/vec4.h"
#include "../math/mat4.h"

#include <variant>
#include <iostream>

namespace gfx
{

typedef std::variant<bool, int, float, math::vec2, math::vec3, math::vec4, math::mat4> UniformTypes;

template <typename T>
struct Uniform
{
    std::string m_name;
    T m_uniform;

    Uniform(T uniform, const char* name) : m_uniform(uniform), m_name(name) {}
    void setUniform(GLuint programId)
    {
        std::visit([this, programId](auto&& uniform) {
            using U = std::decay_t<decltype(uniform)>;

            if constexpr (std::is_same_v<U, bool>)
                Shader::setBool(programId, m_name.c_str(), uniform);
            else if constexpr (std::is_same_v<U, int>)
                Shader::setInt(programId, m_name.c_str(), uniform);
            else if constexpr (std::is_same_v<U, float>)
                Shader::setFloat(programId, m_name.c_str(), uniform);
            else if constexpr (std::is_same_v<U, math::vec2>)
                Shader::setVector2(programId, m_name.c_str(), uniform);
            else if constexpr (std::is_same_v<U, math::vec3>)
                Shader::setVector3(programId, m_name.c_str(), uniform);
            else if constexpr (std::is_same_v<U, math::vec4>)
                Shader::setVector4(programId, m_name.c_str(), uniform);
            else if constexpr (std::is_same_v<U, math::mat4>)
                Shader::setMatrix4(programId, this->m_name.c_str(), uniform);
        }, m_uniform);
    }
};

} // namespace gfx
