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

#include "Math/Mat4.hpp"
#include "Math/Vec3.hpp"

namespace Crane {

class Transform {
public:
  Transform();

  void setPosition(const Math::Vec3& position);
  void move(const Math::Vec3& v);

  void setRotation(const Math::Vec3& rotation);
  void rotate(const Math::Vec3& a);

  void setScale(const Math::Vec3& scale);
  void scale(const Math::Vec3& s);

  void recomputeMatrix();

  inline const Math::Vec3& getPosition() const { return m_Position; }
  inline const Math::Vec3& getRotation() const { return m_Rotation; }
  inline const Math::Vec3& getScale() const { return m_Scale; }

  Math::Vec3 getRotationAngles() const;

  inline const Math::Mat4& getTransformMatrix() const
  {
    return m_TransformMatrix;
  }

private:
  Math::Vec3 m_Position;
  Math::Vec3 m_Rotation;
  Math::Vec3 m_Scale;

  Math::Mat4 m_TransformMatrix;
};

}