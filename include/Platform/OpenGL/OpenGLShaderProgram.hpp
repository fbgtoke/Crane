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

#include "Render/ShaderProgram.hpp"

#include <cstdint>
#include <unordered_map>
#include <string>

namespace Crane {
  
class OpenGLShaderProgram : public ShaderProgram {
public:
  OpenGLShaderProgram();
  virtual ~OpenGLShaderProgram();

  void destroy() override;

  void attach(const Shader * const shader) const override;
  void detach(const Shader * const shader) const override;

  bool link() override;

  void use() const override;

  uint32_t getUniformLocation(const std::string& name) const;

  void setUniform1i(const std::string& name, int v) const override;
  void setUniform1f(const std::string& name, float v) const override;
  void setUniform2f(const std::string& name, float v1, float v2) const override;
  void setUniform3f(const std::string& name, float v1, float v2, float v3) const override;
  void setUniformMat3f(const std::string& name, const float* v) const override;
  void setUniformMat4f(const std::string& name, const float* v) const override;
  void setUniformTexture(const std::string& name, const Texture * const tex) const override;

  inline uint32_t getId() const { return m_Id; }

private:
  uint32_t m_Id;

  void queryUniforms();

  struct Uniform {
    uint32_t location;
    ShaderDatatype type;
    Uniform() {};
    Uniform(uint32_t l, ShaderDatatype t)
      : location(l), type(t) {};
  };
  std::unordered_map<std::string, Uniform> m_Uniforms;
};

}