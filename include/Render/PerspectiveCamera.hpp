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

#include "Camera.hpp"
#include "Transform.hpp"

namespace Crane {
 
class PerspectiveCamera : public Camera {
public:
  PerspectiveCamera(float fov, float ar, float znear, float zfar);

  ~PerspectiveCamera() override = default;

  const Math::Mat4& getViewMatrix() const override
  {
    return  m_Transform.getTransformMatrix();
  }

  const Math::Mat4& getProjectionMatrix() const override
  {
    return  m_ProjectionMatrix;
  }

  const Math::Mat4& getViewProjectionMatrix() const override
  {
    return  m_ViewProjectionMatrix;
  }

  inline Transform& getTransform()
  {
    return m_Transform;
  }
  inline const Transform& getTransform() const
  {
    return m_Transform;
  }

  void recomputeMatrices();

private:
  /* Transform */
  Transform m_Transform;

  /* Matrices */
  Math::Mat4 m_ProjectionMatrix;
  Math::Mat4 m_ViewProjectionMatrix;
};

}