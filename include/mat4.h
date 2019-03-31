/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include <ostream>

#include "vec3.h"
#include "vec4.h"
#include "../utils/mathutils.h"
#include <cmath>

namespace math
{

struct mat4
{
    union
    {
        float m[16];
        vec4 column[4];
    };

    mat4() 
    { 
        reset();
    }
    mat4(float identity)
    {
        reset();

        m[0 + 0 * 4] = identity;
        m[1 + 1 * 4] = identity;
        m[2 + 2 * 4] = identity;
        m[3 + 3 * 4] = identity;
    }

    void reset()
    {
        for (unsigned i = 0; i < 16; i++)
            m[i] = 0.0f;
    }

    inline float& operator()(unsigned row, unsigned col) { return m[row + col * 4]; }
    inline float operator()(unsigned row, unsigned col) const { return m[row + col * 4]; }

    void translate(const vec3 &value);
    void rotate(float angle, const vec3& axis);
    void scale(const vec3 &value);

    void setTranslation(const vec3 &pos)
    {
        m[0 + 3 * 4] = pos.x;
        m[1 + 3 * 4] = pos.y;
        m[2 + 3 * 4] = pos.z;
    }

    void setRotation(float angle, const vec3 &axis)
    {
        float c = cosf(utils::toRadians(angle));
        float s = sinf(utils::toRadians(angle));
        float cmo = 1.0f - c;

        float x = axis.x;
        float y = axis.y;
        float z = axis.z;

        m[0 + 0 * 4] = c + x * x * cmo;
        m[1 + 0 * 4] = y * x * cmo + z * s;
        m[2 + 0 * 4] = z * x * cmo - y * s;

        m[0 + 1 * 4] = x * y * cmo - z * s;
        m[1 + 1 * 4] = c + y * y * cmo;
        m[2 + 1 * 4] = z * y * cmo + x * s;

        m[0 + 2 * 4] = x * z * cmo + y * s;
        m[1 + 2 * 4] = y * z * cmo - x * s;
        m[2 + 2 * 4] = c + z * z * cmo;

        m[3 + 3 * 4] = 1;
    }

    void setScale(const vec3 &scale)
    {
        m[0 + 0 * 4] = scale.x;
        m[1 + 1 * 4] = scale.y;
        m[2 + 2 * 4] = scale.z;
    }

    static mat4 translationMatrix(const vec3 &pos)
    {
        mat4 mat(1.0f);
        mat.setTranslation(pos);
        return mat;
    }

    static mat4 rotationMatrix(float angle, const vec3 &axis)
    {
        mat4 mat(1.0f);
        mat.setRotation(angle, axis);
        return mat;
    }

    static mat4 scaleMatrix(const vec3 &scale)
    {
        mat4 mat(1.0f);
        mat.setScale(scale);
        return mat;
    }

    static mat4 identity() { return mat4(1.0f); }
    static mat4 ortho(float left, float right, float bottom, float top, float nearZ, float farZ)
    {
        mat4 mat(1.0f);

        mat(0, 0) = 2.0f / (right - left);
        mat(1, 1) = 2.0f / (top - bottom);
        mat(2, 2) = -2.0f / (farZ - nearZ);
        mat(0, 3) = -(right + left) / (right - left);
        mat(1, 3) = -(top + bottom) / (top - bottom);
        mat(2, 3) = -(farZ + nearZ) / (farZ - nearZ);

        return mat;

    }
    static mat4 perspective(float fov, float aspect, float nearZ, float farZ)
    {
        mat4 mat(1.0f);

        float q = 1.0f / tanf(utils::toRadians(fov) / 2.0f);

        mat(0, 0) = q / aspect;
        mat(1, 1) = q;
        mat(2, 2) = (farZ + nearZ) / (nearZ - farZ);
        mat(2, 3) = -1.0f;
        mat(3, 2) = 2.0f * (farZ * nearZ) / (nearZ - farZ);
        mat(3, 3) = 0.0f;

        return mat;
    }
};

mat4 operator+(const mat4 &left, const mat4 &right);
mat4 operator+=(mat4 &left, const mat4 &right);
mat4 operator-(const mat4 &left, const mat4 &right);
mat4 operator-=(mat4 &left, const mat4 &right);
mat4 operator*(const mat4 &left, const mat4 &right);
mat4 operator*=(mat4 &left, const mat4 &right);
std::ostream& operator<<(std::ostream& os, const mat4 &mat);

} // namespace math
