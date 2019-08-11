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

#include "PerspectiveCamera.hpp"

#include "Math/MatrixTransform.hpp"

namespace Crane {

PerspectiveCamera::PerspectiveCamera(
  float fov, float ar, float znear, float zfar
) : m_ProjectionMatrix(Math::MatrixTransform::perspective(fov, ar, znear, zfar))
{
  recomputeMatrices();
}

void PerspectiveCamera::recomputeMatrices()
{
  m_ViewMatrix =
    Math::MatrixTransform::translation(-1.f * m_Transform.getPosition()) *
    Math::MatrixTransform::rotation(m_Transform.getRotation().inverse()) *
    Math::MatrixTransform::scale(m_Transform.getScale());

  m_ViewProjectionMatrix = m_ProjectionMatrix * m_ViewMatrix;
}

}