/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include "vec2.h"

#include <tuple>

namespace math 
{

// Overload operators
vec2 operator+(const vec2 &left, const vec2 &right) { return vec2(left.x + right.x, left.y + right.y); }
vec2 operator-(const vec2 &left, const vec2 &right) { return vec2(left.x - right.x, left.y - right.y); }
vec2 operator*(const vec2 &left, const vec2 &right) { return vec2(left.x * right.x, left.y * right.y); }
vec2 operator/(const vec2 &left, const vec2 &right) { return vec2(left.x / right.x, left.y / right.y); }
vec2 operator+=(vec2 &left, const vec2 &right) { left = left + right; return left; }
vec2& operator-=(vec2 &left, const vec2 &right) { left = left - right; return left; }
vec2& operator*=(vec2 &left, const vec2 &right) { left = left * right; return left; }
vec2& operator/=(vec2 &left, const vec2 &right) { left = left / right; return left; }
bool operator==(const vec2 &left, const vec2 &right) { return (left.x == right.x) && (left.y == right.y); }
bool operator!=(const vec2 &left, const vec2 &right) { return (left.x != right.x) || (left.y != right.y); }
std::ostream& operator<<(std::ostream& os, const vec2 &vec) { return os << "[" << vec.x << ", " << vec.y << "]"; }

bool vec2::operator<(const vec2 &vec) const { return std::tie(x, y) < std::tie(vec.x, vec.y); }

} // namespace math