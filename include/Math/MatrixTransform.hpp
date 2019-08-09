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

#include "Mat4.hpp"
#include "Vec3.hpp"

namespace Crane { namespace Math {

class MatrixTransform {
public:
  static Mat4 translation(const Vec3& v);
  static Mat4 translate(const Mat4 m, const Vec3& v);

  static Mat4 rotationX(float a);
  static Mat4 rotationY(float a);
  static Mat4 rotationZ(float a);

  static Mat4 scale(const Vec3& v);

  static Mat4 ortho(
    float l, float r, float b, float t,
    float znear, float zfar
  );
};

} }