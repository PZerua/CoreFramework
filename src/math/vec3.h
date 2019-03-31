/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include <ostream>

#include "vec2.h"
#include <cmath>

namespace math
{

struct vec3
{
    float x, y, z;

    vec3() : x(0), y(0), z(0) {}
    vec3(float x, float y, float z) : x(x), y(y), z(z) {}
    vec3(vec2 xy, float z = 0) : x(xy.x), y(xy.y), z(z) {}

    float dot(const vec3 &vec) const { return (x * vec.x + y * vec.y + z * vec.z); }
    vec3 cross(const vec3 &vec) const { return vec3(y * vec.z - vec.y * z, -(x * vec.z - vec.x * z), x * vec.y - vec.x * y); }
    inline float magnitude() const { return std::sqrt(x*x + y*y + z*z); }

    bool operator<(const vec3 &vec) const;
};

} // namespace math
