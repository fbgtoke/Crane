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

namespace Crane { namespace Math {

class Vec4 {
public:
  Vec4() : x(0.f), y(0.f), z(0.f), w(0.f) {}
  Vec4(float v) : x(v), y(v), z(v), w(v) {}
  Vec4(float v1, float v2, float v3, float v4) : x(v1), y(v2), z(v3), w(v4) {}
  Vec4(const Vec4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {}

  friend Vec4 operator+(Vec4 v1, const Vec4& v2);
  friend Vec4 operator-(Vec4 v1, const Vec4& v2);
  friend Vec4 operator*(float k, const Vec4& v);

  Vec4& operator=(const Vec4& v);
  Vec4& operator+=(const Vec4& v);
  Vec4& operator-=(const Vec4& v);

  friend bool operator==(const Vec4& v1, const Vec4& v2);

  float& operator[](std::size_t idx);
  const float& operator[](std::size_t idx) const;

  float length() const;
  void normalize();

  union
  {
    float values[4];
    struct { float r, g, b, a; };
    struct { float x, y, z, w; };
  };
};

} }