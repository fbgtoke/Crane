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

#include "Math/Vec3.hpp"

namespace Crane {

class Material {
public:
  Material(ShaderProgram& program);

  // To do...
  void set(const std::string& name, float v);

  inline void enableAmbient() { m_UseKa = true; }
  inline void enableDiffuse() { m_UseKd = true; }
  inline void enableSpecular() { m_UseKs = true; }

  inline void disableAmbient() { m_UseKa = false; }
  inline void disableDiffuse() { m_UseKd = false; }
  inline void disableSpecular() { m_UseKs = false; }

  inline const Math::Vec3& getAmbient() const { return m_Ka; }
  inline const Math::Vec3& getDiffuse() const { return m_Kd; }
  inline const Math::Vec3& getSpecular() const { return m_Ks; }
  inline float getSpecularExponent() const { return m_Ns; }

private:
  ShaderProgram& m_Program;

  bool m_UseKa;
  bool m_UseKd;
  bool m_UseKs;

  Math::Vec3 m_Ka;
  Math::Vec3 m_Kd;
  Math::Vec3 m_Ks;
  float m_Ns;
};

}