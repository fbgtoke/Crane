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

#include <glm/gtc/matrix_transform.hpp>

namespace Crane {

Transform::Transform()
  : m_Position(0.f), m_Rotation(0.f), m_Scale(1.f), m_TransformMatrix(1.f) {}

void Transform::setPosition(const glm::vec3& position)
{
  m_Position = position;
}
void Transform::move(const glm::vec3& v)
{
  m_Position += v;
}

void Transform::setRotation(const glm::vec3& rotation)
{
  m_Rotation = rotation;
}
void Transform::rotate(const glm::vec3& a)
{
  m_Rotation += a;
}

void Transform::setScale(const glm::vec3& scale)
{
  m_Scale = scale;
}
void Transform::scale(const glm::vec3& s)
{
  m_Scale += s;
}

void Transform::recomputeMatrix()
{
  m_TransformMatrix = glm::mat4(1.f);

  m_TransformMatrix =
    glm::translate(m_TransformMatrix, m_Position);
  m_TransformMatrix =
    glm::rotate(m_TransformMatrix, m_Rotation.z, { 0.f, 0.f, 1.f });
  m_TransformMatrix =
    glm::rotate(m_TransformMatrix, m_Rotation.y, { 0.f, 1.f, 0.f });
  m_TransformMatrix =
    glm::rotate(m_TransformMatrix, m_Rotation.x, { 1.f, 0.f, 0.f });
  m_TransformMatrix =
    glm::scale(m_TransformMatrix, m_Scale);
}


}