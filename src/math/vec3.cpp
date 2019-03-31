/**
* (c) 2017 Pablo Luis García. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#pragma once

#include "vec3.h"

#include <tuple>

namespace math 
{

// Overload operators
vec3 operator+(const vec3 &left, const vec3 &right) { return vec3(left.x + right.x, left.y + right.y, left.z + right.z); }
vec3 operator-(const vec3 &left, const vec3 &right) { return vec3(left.x - right.x, left.y - right.y, left.z - right.z); }
vec3 operator*(const vec3 &left, const vec3 &right) { return vec3(left.x * right.x, left.y * right.y, left.z * right.z); }
vec3 operator/(const vec3 &left, const vec3 &right) { return vec3(left.x / right.x, left.y / right.y, left.z / right.z); }
vec3 operator+=(vec3 &left, const vec3 &right) { left = left + right; return left; }
vec3 operator-=(vec3 &left, const vec3 &right) { left = left - right; return left; }
vec3 operator*=(vec3 &left, const vec3 &right) { left = left * right; return left; }
vec3 operator/=(vec3 &left, const vec3 &right) { left = left / right; return left; }
bool operator==(const vec3 &left, const vec3 &right) { return (left.x == right.x) && (left.y == right.y) && (left.z == right.z); }
bool operator!=(const vec3 &left, const vec3 &right) { return (left.x != right.x) || (left.y != right.y) || (left.z != right.z); }
std::ostream& operator<<(std::ostream& os, const vec3 &vec) { return os << "[" << vec.x << ", " << vec.y << ", " << vec.z << "]"; }

bool vec3::operator<(const vec3 &vec) const { return std::tie(x, y, z) < std::tie(vec.x, vec.y, vec.z); }

} // namespace math