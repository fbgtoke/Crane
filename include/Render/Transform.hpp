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

#include <glm/gtx/quaternion.hpp>
#include <glm/mat4x4.hpp>
#include <glm/vec3.hpp>

namespace Crane {

class Transform {
public:
  Transform();

  void setPosition(const glm::vec3& position);
  void move(const glm::vec3& v);

  void setRotation(const glm::vec3& rotation);
  void rotate(const glm::vec3& a);

  void setScale(const glm::vec3& scale);
  void scale(const glm::vec3& s);

  void recomputeMatrix();

  inline const glm::mat4& getTransformMatrix() const
  {
    return m_TransformMatrix;
  }

private:
  glm::vec3 m_Position;
  glm::quat m_Rotation;
  glm::vec3 m_Scale;

  glm::mat4 m_TransformMatrix;
};

}