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

#include "Vec3.hpp"

namespace Crane { namespace Math {

class Quat {
public:
  Quat()
    : i(0.f), j(0.f), k(0.f), w(1.f) {}
  Quat(float v1, float v2, float v3, float v4)
    : i(v1), j(v2), k(v3), w(v4) {}

  friend Quat operator*(const Quat& q1, const Quat& q2);

  static Quat fromEuler(float roll, float pitch, float yaw);
  inline static Quat fromEuler(const Vec3& v)
  {
    return fromEuler(v.x, v.y, v.z);
  }
  static Quat fromAxisAngle(float a, const Vec3& v);

  static Vec3 toEuler(const Quat& q);


  float length() const;
  void normalize();

  union
  {
    float values[4];
    struct { float i, j, k, w; };
  };
};

} }