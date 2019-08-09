// Crane game engine
// Copyright (C) 2019  Fabio Banchelli
// 
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program. If not, see <http://www.gnu.org/licenses/>.

#include "Vec4.hpp"

namespace Crane { namespace Math {

Vec4 operator+(Vec4 v1, const Vec4& v2)
{
  return Vec4(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, v1.w + v2.w);
}

Vec4 operator-(Vec4 v1, const Vec4& v2)
{
  return Vec4(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, v1.w - v2.w);
}

Vec4 operator*(float k, const Vec4& v)
{
  return Vec4(v.x*k, v.y*k, v.z*k, v.w*k);
}

Vec4& Vec4::operator=(const Vec4& v)
{
  x = v.x;
  y = v.y;
  z = v.z;
  w = v.w;
  return *this;
}

Vec4& Vec4::operator+=(const Vec4& v)
{
  x += v.x;
  y += v.y;
  z += v.z;
  w += v.w;
  return *this;
}

Vec4& Vec4::operator-=(const Vec4& v)
{
  x -= v.x;
  y -= v.y;
  z -= v.z;
  w -= v.w;
  return *this;
}

bool operator==(const Vec4& v1, const Vec4& v2)
{
  return (v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z) && (v1.w == v2.w);
}

float& Vec4::operator[](std::size_t idx)
{
  return values[idx];
}
const float& Vec4::operator[](std::size_t idx) const
{
  return values[idx];
}

float Vec4::length() const
{
  return std::sqrt(x*x + y*y + z*z + w*w);
}

void Vec4::normalize()
{
  x *= 1.f/length();
  y *= 1.f/length();
  z *= 1.f/length();
  w *= 1.f/length();
}

} }