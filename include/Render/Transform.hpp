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

#include "Core/Mat4.hpp"
#include "Core/Vec3.hpp"

namespace Crane {

class Transform {
public:
  Transform();

  void setPosition(const Vec3& position);
  void move(const Vec3& v);

  void setRotation(const Vec3& rotation);
  void rotate(const Vec3& a);

  void setScale(const Vec3& scale);
  void scale(const Vec3& s);

  void recomputeMatrix();

  inline const Vec3& getPosition() const { return m_Position; }
  inline const Vec3& getRotation() const { return m_Rotation; }
  inline const Vec3& getScale() const { return m_Scale; }

  Vec3 getRotationAngles() const;

  inline const Matrix4& getTransformMatrix() const
  {
    return m_TransformMatrix;
  }

private:
  Vec3 m_Position;
  Vec3 m_Rotation;
  Vec3 m_Scale;

  Matrix4 m_TransformMatrix;
};

}