/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include <ostream>

#include "vec3.h"
#include <cmath>

namespace math
{

struct vec4
{
    float x, y, z, w;

    vec4() : x(0), y(0), z(0), w(0) {}
    vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {}
    vec4(vec3 xyz, float w) : x(xyz.x), y(xyz.y), z(xyz.z), w(w) {}

    float dot(const vec4 &vec) const { return (x * vec.x + y * vec.y + z * vec.z + w * vec.w); }
    inline float magnitude() const { return std::sqrt(x*x + y*y + z*z + w*w); }

    bool vec4::operator<(const vec4 &vec) const;
};

} // namespace math