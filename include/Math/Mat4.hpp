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

#include "Vec4.hpp"

namespace Crane { namespace Math {

class Mat4 {
public:
  Mat4();
  Mat4(float v);
  Mat4(const Mat4& v);

  friend Mat4 operator+(Mat4 v1, const Mat4& v2);
  friend Mat4 operator-(Mat4 v1, const Mat4& v2);
  friend Mat4 operator*(float k, const Mat4& v);
  friend Mat4 operator*(const Mat4& v1, const Mat4& v2);
  friend Vec4 operator*(const Mat4& m, const Vec4& v);

  Mat4& operator=(const Mat4& v);
  Mat4& operator+=(const Mat4& v);
  Mat4& operator-=(const Mat4& v);

  friend bool operator==(const Mat4& v1, const Mat4& v2);

  float* operator[](std::size_t idx);
  const float* operator[](std::size_t idx) const;

  float values[4][4];
};

} }