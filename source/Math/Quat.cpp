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

#include "Quat.hpp"

#include <cmath>

namespace Crane { namespace Math {

Quat operator*(const Quat& q1, const Quat& q2)
{
  Quat q;
  q.w = q1.w*q2.w - q1.i*q2.i - q1.j*q2.j - q1.k*q2.k;
  q.i = q1.w*q2.i + q1.i*q2.w + q1.j*q2.k - q1.k*q2.j;
  q.j = q1.w*q2.j - q1.i*q2.k + q1.j*q2.w + q1.k*q2.i;
  q.k = q1.w*q2.k + q1.i*q2.j - q1.j*q2.i + q1.k*q2.w;
  return q;
}

Quat Quat::fromEuler(float roll, float pitch, float yaw)
{
  float cy = cos(  yaw * 0.5f);
  float sy = sin(  yaw * 0.5f);
  float cp = cos(pitch * 0.5f);
  float sp = sin(pitch * 0.5f);
  float cr = cos( roll * 0.5f);
  float sr = sin( roll * 0.5f);

  Quat q;
  q.w = cy * cp * cr + sy * sp * sr;
  q.i = cy * cp * sr - sy * sp * cr;
  q.j = sy * cp * sr + cy * sp * cr;
  q.k = sy * cp * cr - cy * sp * sr;
  return q;
}

Quat Quat::fromAxisAngle(float a, const Vec3& v)
{
  Vec3 vn = v;
  vn.normalize();

  Quat q;
  q.i = vn.x * sin(a*.5f);
  q.j = vn.y * sin(a*.5f);
  q.k = vn.z * sin(a*.5f);
  q.w = cos(a*.5f);
  return q;
}

Vec3 Quat::toEuler(const Quat& q)
{
  Vec3 v;
  v.x = atan2(2.f * (q.w*q.i + q.j*q.k), 1.f - 2.f * (q.i*q.i + q.j*q.j));
  v.y =  asin(2.f * (q.w*q.j - q.k*q.i));
  v.z = atan2(2.f * (q.w*q.k + q.i*q.j), 1.f - 2.f * (q.j*q.j* + q.k*q.k));
  return v;
}

float Quat::length() const
{
  return std::sqrt(w*w + i*i + j*j + k*k);
}

void Quat::normalize()
{
  w *= 1.f/length();
  i *= 1.f/length();
  j *= 1.f/length();
  k *= 1.f/length();
}

} }