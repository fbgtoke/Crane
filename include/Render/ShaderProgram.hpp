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

#include "Shader.hpp"

#include <string>

namespace Crane {
  
class ShaderProgram {
public:
  ShaderProgram();
  ~ShaderProgram();

  void create();
  void destroy();

  void attach(const Shader& shader) const;
  void detach(const Shader& shader) const;

  bool link();

  void use() const;

  void setUniform1i(unsigned int location, int v) const;
  void setUniform1f(unsigned int location, float v) const;
  void setUniform2f(unsigned int location, float v1, float v2) const;
  void setUniform3f(unsigned int location, float v1, float v2, float v3) const;
  void setUniformMat3f(unsigned int location, const float* v) const;
  void setUniformMat4f(unsigned int location, const float* v) const;

  inline unsigned int getId() const { return m_Id; }
  inline bool isLinked() const { return m_Linked; }

  inline std::string getInfoLog() const { return m_InfoLog; }

private:
  unsigned int m_Id;

  bool m_Linked;
  std::string m_InfoLog;
};

}