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

#pragma once

#include <cmath>

namespace Crane {

class Vec3 {
public:
  Vec3() : x(0.f), y(0.f), z(0.f) {}
  Vec3(float v) : x(v), y(v), z(v) {}
  Vec3(float v1, float v2, float v3) : x(v1), y(v2), z(v3) {}
  Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {}

  friend Vec3 operator+(Vec3 v1, const Vec3& v2);
  friend Vec3 operator-(Vec3 v1, const Vec3& v2);
  friend Vec3 operator*(float k, const Vec3& v);

  Vec3& operator=(const Vec3& v);
  Vec3& operator+=(const Vec3& v);
  Vec3& operator-=(const Vec3& v);

  friend bool operator==(const Vec3& v1, const Vec3& v2);

  float& operator[](std::size_t idx);
  const float& operator[](std::size_t idx) const;

  static float length(const Vec3& v);
  static Vec3 normalize(const Vec3& v);

  union
  {
    float values[3];
    struct { float r, g, b; };
    struct { float x, y, z; };
  };
};

}