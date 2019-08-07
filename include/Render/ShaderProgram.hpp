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
#include "Texture.hpp"

#include <string>
#include <unordered_map>

namespace Crane {
  
class ShaderProgram {
public:
  ShaderProgram() = default;
  virtual ~ShaderProgram() = default;

  static ShaderProgram* create();
  virtual void destroy() = 0;

  virtual void attach(const Shader * const shader) const = 0;
  virtual void detach(const Shader * const shader) const = 0;

  virtual bool link() = 0;

  virtual void use() const = 0;

  virtual void setUniform1i(const std::string& name, int v) const = 0;
  virtual void setUniform1f(const std::string& name, float v) const = 0;
  virtual void setUniform2f(const std::string& name, float v1, float v2) const = 0;
  virtual void setUniform3f(const std::string& name, float v1, float v2, float v3) const = 0;
  virtual void setUniformMat3f(const std::string& name, const float* v) const = 0;
  virtual void setUniformMat4f(const std::string& name, const float* v) const = 0;
  virtual void setUniformTexture(const std::string& name, const Texture * const tex) const = 0;
};

}