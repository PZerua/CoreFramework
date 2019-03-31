/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include <ostream>
#include <cmath>

namespace math 
{

struct vec2
{
    float x, y;

    vec2() : x(0), y(0) {}
    vec2(float x, float y) : x(x), y(y) {}

    float dot(const vec2 &vec) const { return (x * vec.x + y * vec.y); }
    inline float magnitude() const { return std::sqrt(x*x + y * y); }

    bool operator<(const vec2 &vec) const;
};

} // namespace math