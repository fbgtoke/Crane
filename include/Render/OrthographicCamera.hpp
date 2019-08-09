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

#include "Math/Vec3.hpp"

namespace Crane {
 
class OrthographicCamera : public Camera {
public:
  OrthographicCamera(
    float l, float r, float b, float t, 
    float znear = -1.f, float zfar = 1.f
  );

  ~OrthographicCamera() override = default;

  const Math::Mat4& getViewMatrix() const override
  {
    return  m_ViewMatrix;
  }

  const Math::Mat4& getProjectionMatrix() const override
  {
    return  m_ProjectionMatrix;
  }

  const Math::Mat4& getViewProjectionMatrix() const override
  {
    return  m_ViewProjectionMatrix;
  }

  void setPosition(const Math::Vec3& position);
  void move(const Math::Vec3& v);

  void setRotation(float rotation);
  void rotate(float v);

  void recomputeMatrices();

  inline Math::Vec3 getPosition() const { return m_Position; }
  inline float getRotation() const { return m_Rotation; }

private:
  /* View */
  Math::Vec3 m_Position;
  float m_Rotation;

  /* Matrices */
  Math::Mat4 m_ViewMatrix;
  Math::Mat4 m_ProjectionMatrix;
  Math::Mat4 m_ViewProjectionMatrix;
};

}