/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include "mat4.h"

namespace math
{

void mat4::translate(const vec3 &value)
{
    mat4 T(1.0f);
    T.setTranslation(value);

    *this *= T;
}

void mat4::rotate(float angle, const vec3& axis)
{
    mat4 R(1.0f);
    R.setRotation(angle, axis);

    *this *= R;
}

void mat4::scale(const vec3 &value)
{
    mat4 S(1.0f);
    S.setScale(value);

    *this *= S;
}

mat4 operator+(const mat4 &left, const mat4 &right) 
{ 
    mat4 sum;

    for (unsigned i = 0; i < 16; i++)
        sum.m[i] = left.m[i] + right.m[i];

    return sum;
}

mat4 operator+=(mat4 &left, const mat4 &right)
{
    left = left + right;
    return left;
}

mat4 operator-(const mat4 &left, const mat4 &right)
{
    mat4 sub;

    for (unsigned i = 0; i < 16; i++)
        sub.m[i] = left.m[i] - right.m[i];

    return sub;
}

mat4 operator-=(mat4 &left, const mat4 &right)
{
    left = left - right;
    return left;
}

mat4 operator*(const mat4 &left, const mat4 &right)
{
    mat4 mul;

    for (unsigned row = 0; row < 4; row++)
        for (unsigned e = 0; e < 4; e++)
            for (unsigned col = 0; col < 4; col++)
                mul(row, col) += left(row, e) * right(e, col);

    return mul;
}

mat4 operator*=(mat4 &left, const mat4 &right)
{
    left = left * right;
    return left;
}

std::ostream& operator<<(std::ostream& os, const mat4 &mat) 
{ 
    for (unsigned col = 0; col < 4; col++)
    {
        os << "| ";

        for (unsigned row = 0; row < 4; row++)
            os << mat(col, row) << " ";

        os << "|" << std::endl;
    }

    return os;
}

} // namespace math
