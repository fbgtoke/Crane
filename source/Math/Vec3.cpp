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

#include "Vec3.hpp"

namespace Crane { namespace Math {

Vec3 operator+(Vec3 v1, const Vec3& v2)
{
  return Vec3(v1.x + v2.x, v1.y + v2.y, v1.z + v2.z);
}

Vec3 operator-(Vec3 v1, const Vec3& v2)
{
  return Vec3(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

Vec3 operator*(float k, const Vec3& v)
{
  return Vec3(v.x*k, v.y*k, v.z*k);
}

Vec3& Vec3::operator=(const Vec3& v)
{
  x = v.x;
  y = v.y;
  z = v.z;
  return *this;
}

Vec3& Vec3::operator+=(const Vec3& v)
{
  x += v.x;
  y += v.y;
  z += v.z;
  return *this;
}

Vec3& Vec3::operator-=(const Vec3& v)
{
  x -= v.x;
  y -= v.y;
  z -= v.z;
  return *this;
}

bool operator==(const Vec3& v1, const Vec3& v2)
{
  return (v1.x == v2.x) && (v1.y == v2.y) && (v1.z == v2.z);
}

float& Vec3::operator[](std::size_t idx)
{
  return values[idx];
}
const float& Vec3::operator[](std::size_t idx) const
{
  return values[idx];
}

float Vec3::length(const Vec3& v)
{
  return std::sqrt(v.x*v.x + v.y*v.y + v.z*v.z);
}

Vec3 Vec3::normalize(const Vec3& v)
{
  return 1.f/length(v) * v;
}

} }