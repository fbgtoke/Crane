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

#include "Math/MatrixTransform.hpp"

namespace Crane {

Transform::Transform()
  : m_Position(0.f), m_Rotation(), m_Scale(1.f), m_TransformMatrix(1.f) {}

void Transform::setPosition(const Math::Vec3& position)
{
  m_Position = position;
}
void Transform::move(const Math::Vec3& v)
{
  m_Position += v;
}

void Transform::setRotation(const Math::Vec3& rotation)
{
  Math::Quat qx = Math::Quat::fromAxisAngle(rotation.x, Math::Vec3(1.f, 0.f, 0.f));
  Math::Quat qy = Math::Quat::fromAxisAngle(rotation.y, Math::Vec3(0.f, 1.f, 0.f));
  Math::Quat qz = Math::Quat::fromAxisAngle(rotation.z, Math::Vec3(0.f, 0.f, 1.f));
  m_Rotation = qx * qy * qz;
}
void Transform::rotate(const Math::Vec3& a)
{
  Math::Quat qx = Math::Quat::fromAxisAngle(a.x, Math::Vec3(1.f, 0.f, 0.f));
  Math::Quat qy = Math::Quat::fromAxisAngle(a.y, Math::Vec3(0.f, 1.f, 0.f));
  Math::Quat qz = Math::Quat::fromAxisAngle(a.z, Math::Vec3(0.f, 0.f, 1.f));
  m_Rotation = qx * qy * qz * m_Rotation;
}

void Transform::setScale(const Math::Vec3& scale)
{
  m_Scale = scale;
}
void Transform::scale(const Math::Vec3& s)
{
  m_Scale += s;
}

void Transform::recomputeMatrix()
{
  m_TransformMatrix =
    Math::MatrixTransform::translation(m_Position) *
    Math::MatrixTransform::rotation(m_Rotation) *
    Math::MatrixTransform::scale(m_Scale);
}

Math::Vec3 Transform::getRotationAngles() const
{
  return Math::Quat::toEuler(m_Rotation);
}

}