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

#include "Transform.hpp"

#include "Core/MatrixTransform.hpp"

namespace Crane {

Transform::Transform()
  : m_Position(0.f), m_Rotation(0.f), m_Scale(1.f), m_TransformMatrix(1.f) {}

void Transform::setPosition(const Vec3& position)
{
  m_Position = position;
}
void Transform::move(const Vec3& v)
{
  m_Position += v;
}

void Transform::setRotation(const Vec3& rotation)
{
  /*glm::quat qx = glm::angleAxis(rotation.x, Vec3(1.f, 0.f, 0.f));
  glm::quat qy = glm::angleAxis(rotation.y, Vec3(0.f, 1.f, 0.f));
  glm::quat qz = glm::angleAxis(rotation.z, Vec3(0.f, 0.f, 1.f));
  m_Rotation = qx * qy * qz;*/
  m_Rotation = rotation;
}
void Transform::rotate(const Vec3& a)
{
  /*glm::quat qx = glm::angleAxis(a.x, Vec3(1.f, 0.f, 0.f));
  glm::quat qy = glm::angleAxis(a.y, Vec3(0.f, 1.f, 0.f));
  glm::quat qz = glm::angleAxis(a.z, Vec3(0.f, 0.f, 1.f));
  m_Rotation = qx * qy * qz * m_Rotation;*/
  m_Rotation += a;
}

void Transform::setScale(const Vec3& scale)
{
  m_Scale = scale;
}
void Transform::scale(const Vec3& s)
{
  m_Scale += s;
}

void Transform::recomputeMatrix()
{
  m_TransformMatrix =
    MatrixTransform::translation(m_Position) *
    MatrixTransform::rotationY(m_Rotation.y) *
    MatrixTransform::rotationZ(m_Rotation.z) *
    MatrixTransform::rotationX(m_Rotation.z) *
    MatrixTransform::scale(m_Scale);
}

Vec3 Transform::getRotationAngles() const
{
  //return glm::eulerAngles(m_Rotation);
  return m_Rotation;
}

}