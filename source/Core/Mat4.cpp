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

#include <cstring>

namespace Crane {

Matrix4::Matrix4()
{
  memset(values, 0, 16 * sizeof(float));
}

Matrix4::Matrix4(float v)
{
  memset(values, 0, 16 * sizeof(float));
  values[0][0] = v;
  values[1][1] = v;
  values[2][2] = v;
  values[3][3] = v;
}

Matrix4::Matrix4(const Matrix4& v)
{
  memcpy(values, v.values, 16 * sizeof(float));
}

Matrix4 operator+(Matrix4 v1, const Matrix4& v2)
{
  Matrix4 m;
  m[0][0] = v1[0][0] + v2[0][0];
  m[1][0] = v1[1][0] + v2[1][0];
  m[2][0] = v1[2][0] + v2[2][0];
  m[3][0] = v1[3][0] + v2[3][0];
  m[0][1] = v1[0][1] + v2[0][1];
  m[1][1] = v1[1][1] + v2[1][1];
  m[2][1] = v1[2][1] + v2[2][1];
  m[3][1] = v1[3][1] + v2[3][1];
  m[0][2] = v1[0][2] + v2[0][2];
  m[1][2] = v1[1][2] + v2[1][2];
  m[2][2] = v1[2][2] + v2[2][2];
  m[3][2] = v1[3][2] + v2[3][2];
  m[0][3] = v1[0][3] + v2[0][3];
  m[1][3] = v1[1][3] + v2[1][3];
  m[2][3] = v1[2][3] + v2[2][3];
  m[3][3] = v1[3][3] + v2[3][3];
  return m;
}

Matrix4 operator-(Matrix4 v1, const Matrix4& v2)
{
  Matrix4 m;
  m[0][0] = v1[0][0] - v2[0][0];
  m[1][0] = v1[1][0] - v2[1][0];
  m[2][0] = v1[2][0] - v2[2][0];
  m[3][0] = v1[3][0] - v2[3][0];
  m[0][1] = v1[0][1] - v2[0][1];
  m[1][1] = v1[1][1] - v2[1][1];
  m[2][1] = v1[2][1] - v2[2][1];
  m[3][1] = v1[3][1] - v2[3][1];
  m[0][2] = v1[0][2] - v2[0][2];
  m[1][2] = v1[1][2] - v2[1][2];
  m[2][2] = v1[2][2] - v2[2][2];
  m[3][2] = v1[3][2] - v2[3][2];
  m[0][3] = v1[0][3] - v2[0][3];
  m[1][3] = v1[1][3] - v2[1][3];
  m[2][3] = v1[2][3] - v2[2][3];
  m[3][3] = v1[3][3] - v2[3][3];
  return m;
}

Matrix4 operator*(float k, const Matrix4& v)
{
  Matrix4 m;
  m[0][0] = v[0][0] * k;
  m[1][0] = v[1][0] * k;
  m[2][0] = v[2][0] * k;
  m[3][0] = v[3][0] * k;
  m[0][1] = v[0][1] * k;
  m[1][1] = v[1][1] * k;
  m[2][1] = v[2][1] * k;
  m[3][1] = v[3][1] * k;
  m[0][2] = v[0][2] * k;
  m[1][2] = v[1][2] * k;
  m[2][2] = v[2][2] * k;
  m[3][2] = v[3][2] * k;
  m[0][3] = v[0][3] * k;
  m[1][3] = v[1][3] * k;
  m[2][3] = v[2][3] * k;
  m[3][3] = v[3][3] * k;
  return m;
}

Matrix4 operator*(const Matrix4& v1, const Matrix4& v2)
{
  Matrix4 m;
  m[0][0] = v1[0][0] * v2[0][0] +
            v1[1][0] * v2[0][1] +
            v1[2][0] * v2[0][2] +
            v1[3][0] * v2[0][3];

  m[1][0] = v1[0][0] * v2[1][0] +
            v1[1][0] * v2[1][1] +
            v1[2][0] * v2[1][2] +
            v1[3][0] * v2[1][3];

  m[2][0] = v1[0][0] * v2[2][0] +
            v1[1][0] * v2[2][1] +
            v1[2][0] * v2[2][2] +
            v1[3][0] * v2[2][3];

  m[3][0] = v1[0][0] * v2[3][0] +
            v1[1][0] * v2[3][1] +
            v1[2][0] * v2[3][2] +
            v1[3][0] * v2[3][3];

  m[0][1] = v1[0][1] * v2[0][0] +
            v1[1][1] * v2[0][1] +
            v1[2][1] * v2[0][2] +
            v1[3][1] * v2[0][3];

  m[1][1] = v1[0][1] * v2[1][0] +
            v1[1][1] * v2[1][1] +
            v1[2][1] * v2[1][2] +
            v1[3][1] * v2[1][3];

  m[2][1] = v1[0][1] * v2[2][0] +
            v1[1][1] * v2[2][1] +
            v1[2][1] * v2[2][2] +
            v1[3][1] * v2[2][3];

  m[3][1] = v1[0][1] * v2[3][0] +
            v1[1][1] * v2[3][1] +
            v1[2][1] * v2[3][2] +
            v1[3][1] * v2[3][3];

  m[0][2] = v1[0][2] * v2[0][0] +
            v1[1][2] * v2[0][1] +
            v1[2][2] * v2[0][2] +
            v1[3][2] * v2[0][3];

  m[1][2] = v1[0][2] * v2[1][0] +
            v1[1][2] * v2[1][1] +
            v1[2][2] * v2[1][2] +
            v1[3][2] * v2[1][3];

  m[2][2] = v1[0][2] * v2[2][0] +
            v1[1][2] * v2[2][1] +
            v1[2][2] * v2[2][2] +
            v1[3][2] * v2[2][3];

  m[3][2] = v1[0][2] * v2[3][0] +
            v1[1][2] * v2[3][1] +
            v1[2][2] * v2[3][2] +
            v1[3][2] * v2[3][3];

  m[0][3] = v1[0][3] * v2[0][0] +
            v1[1][3] * v2[0][1] +
            v1[2][3] * v2[0][2] +
            v1[3][3] * v2[0][3];

  m[1][3] = v1[0][3] * v2[1][0] +
            v1[1][3] * v2[1][1] +
            v1[2][3] * v2[1][2] +
            v1[3][3] * v2[1][3];

  m[2][3] = v1[0][3] * v2[2][0] +
            v1[1][3] * v2[2][1] +
            v1[2][3] * v2[2][2] +
            v1[3][3] * v2[2][3];

  m[3][3] = v1[0][3] * v2[3][0] +
            v1[1][3] * v2[3][1] +
            v1[2][3] * v2[3][2] +
            v1[3][3] * v2[3][3];    
  return m;
}

Vec4 operator*(const Matrix4& m, const Vec4& v)
{
  Vec4 res;
  res[0] = m[0][0] * v[0] +
           m[1][0] * v[1] +
           m[2][0] * v[2] +
           m[3][0] * v[3];

  res[1] = m[0][1] * v[0] +
           m[1][1] * v[1] +
           m[2][1] * v[2] +
           m[3][1] * v[3];

  res[2] = m[0][2] * v[0] +
           m[1][2] * v[1] +
           m[2][2] * v[2] +
           m[3][2] * v[3];

  res[3] = m[0][3] * v[0] +
           m[1][3] * v[1] +
           m[2][3] * v[2] +
           m[3][3] * v[3];

  return res;
}

Matrix4& Matrix4::operator=(const Matrix4& v)
{
  memcpy(values, v.values, 16 * sizeof(float));
}

Matrix4& Matrix4::operator+=(const Matrix4& v)
{
  values[0][0] += v[0][0];
  values[1][0] += v[1][0];
  values[2][0] += v[2][0];
  values[3][0] += v[3][0];
  values[0][1] += v[0][1];
  values[1][1] += v[1][1];
  values[2][1] += v[2][1];
  values[3][1] += v[3][1];
  values[0][2] += v[0][2];
  values[1][2] += v[1][2];
  values[2][2] += v[2][2];
  values[3][2] += v[3][2];
  values[0][3] += v[0][3];
  values[1][3] += v[1][3];
  values[2][3] += v[2][3];
  values[3][3] += v[3][3];
  return *this;
}

Matrix4& Matrix4::operator-=(const Matrix4& v)
{
  values[0][0] -= v[0][0];
  values[1][0] -= v[1][0];
  values[2][0] -= v[2][0];
  values[3][0] -= v[3][0];
  values[0][1] -= v[0][1];
  values[1][1] -= v[1][1];
  values[2][1] -= v[2][1];
  values[3][1] -= v[3][1];
  values[0][2] -= v[0][2];
  values[1][2] -= v[1][2];
  values[2][2] -= v[2][2];
  values[3][2] -= v[3][2];
  values[0][3] -= v[0][3];
  values[1][3] -= v[1][3];
  values[2][3] -= v[2][3];
  values[3][3] -= v[3][3];
  return *this;
}

bool operator==(const Matrix4& v1, const Matrix4& v2)
{
  return
    (v1[0][0] == v2[0][0]) &&
    (v1[1][0] == v2[1][0]) &&
    (v1[2][0] == v2[2][0]) &&
    (v1[3][0] == v2[3][0]) &&
    (v1[0][1] == v2[0][1]) &&
    (v1[1][1] == v2[1][1]) &&
    (v1[2][1] == v2[2][1]) &&
    (v1[3][1] == v2[3][1]) &&
    (v1[0][2] == v2[0][2]) &&
    (v1[1][2] == v2[1][2]) &&
    (v1[2][2] == v2[2][2]) &&
    (v1[3][2] == v2[3][2]) &&
    (v1[0][3] == v2[0][3]) &&
    (v1[1][3] == v2[1][3]) &&
    (v1[2][3] == v2[2][3]) &&
    (v1[3][3] == v2[3][3]);
}

float* Matrix4::operator[](std::size_t idx)
{
  return values[idx];
}
const float* Matrix4::operator[](std::size_t idx) const
{
  return values[idx];
}

}