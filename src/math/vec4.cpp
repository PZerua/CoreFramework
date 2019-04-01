/**
* (c) 2017 Pablo Luis Garc�a. All rights reserved.
* Released under MIT license. Read LICENSE for more details.
*/

#include "vec4.h"

#include <tuple>

namespace math
{

// Overload operators
vec4 operator+(const vec4 &left, const vec4 &right) { return vec4(left.x + right.x, left.y + right.y, left.z + right.z, left.w + right.z); }
vec4 operator-(const vec4 &left, const vec4 &right) { return vec4(left.x - right.x, left.y - right.y, left.z - right.z, left.w - right.z); }
vec4 operator*(const vec4 &left, const vec4 &right) { return vec4(left.x * right.x, left.y * right.y, left.z * right.z, left.w * right.z); }
vec4 operator/(const vec4 &left, const vec4 &right) { return vec4(left.x / right.x, left.y / right.y, left.z / right.z, left.w / right.z); }
vec4 operator+=(vec4 &left, const vec4 &right) { left = left + right; return left; }
vec4 operator-=(vec4 &left, const vec4 &right) { left = left - right; return left; }
vec4 operator*=(vec4 &left, const vec4 &right) { left = left * right; return left; }
vec4 operator/=(vec4 &left, const vec4 &right) { left = left / right; return left; }
bool operator==(const vec4 &left, const vec4 &right) { return (left.x == right.x) && (left.y == right.y) && (left.z == right.z) && (left.w == right.w); }
bool operator!=(const vec4 &left, const vec4 &right) { return (left.x != right.x) || (left.y != right.y) || (left.z != right.z) || (left.w != right.w); }
std::ostream& operator<<(std::ostream& os, const vec4 &vec) { return os << "[" << vec.x << ", " << vec.y << ", " << vec.z << ", " << vec.w << "]"; }

bool vec4::operator<(const vec4 &vec) const { return std::tie(x, y, z, w) < std::tie(vec.x, vec.y, vec.z, vec.w); }

} // namespace math
