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

#include "MatrixTransform.hpp"

namespace Crane { namespace Math {

Mat4 MatrixTransform::translation(const Vec3& v)
{
  Mat4 m(1.f);
  m[3][0] = v.x;
  m[3][1] = v.y;
  m[3][2] = v.z;
  return m;
}

Mat4 MatrixTransform::translate(const Mat4 m, const Vec3& v)
{
  Mat4 res(m);
  res[3][0] += v.x;
  res[3][1] += v.y;
  res[3][2] += v.z;
  return res;
}

Mat4 MatrixTransform::rotationX(float a)
{
  Mat4 m;
  m[0][0] = 1; m[1][0] =      0; m[2][0] =       0; m[3][0] = 0;
  m[0][1] = 0; m[1][1] = cos(a); m[2][1] = -sin(a); m[3][1] = 0;
  m[0][2] = 0; m[1][2] = sin(a); m[2][2] =  cos(a); m[3][2] = 0;
  m[0][3] = 0; m[1][3] =      0; m[2][3] =       0; m[3][3] = 1;
  return m;
}

Mat4 MatrixTransform::rotationY(float a)
{
  Mat4 m;
  m[0][0] =  cos(a); m[1][0] = 0; m[2][0] = sin(a); m[3][0] = 0;
  m[0][1] =       0; m[1][1] = 1; m[2][1] =      0; m[3][1] = 0;
  m[0][2] = -sin(a); m[1][2] = 0; m[2][2] = cos(a); m[3][2] = 0;
  m[0][3] =       0; m[1][3] = 0; m[2][3] =      0; m[3][3] = 1;
  return m;
}

Mat4 MatrixTransform::rotationZ(float a)
{
  Mat4 m;
  m[0][0] = cos(a); m[1][0] = -sin(a); m[2][0] = 0; m[3][0] = 0;
  m[0][1] = sin(a); m[1][1] =  cos(a); m[2][1] = 0; m[3][1] = 0;
  m[0][2] =      0; m[1][2] =       0; m[2][2] = 1; m[3][2] = 0;
  m[0][3] =      0; m[1][3] =       0; m[2][3] = 0; m[3][3] = 1;
  return m;
}

Mat4 MatrixTransform::scale(const Vec3& v)
{
  Mat4 m(1.f);
  m[0][0] = v.x;
  m[1][1] = v.y;
  m[2][2] = v.z;
  return m;
}

} }