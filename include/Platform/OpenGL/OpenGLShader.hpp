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

#include "Render/Shader.hpp"

#include <cstdint>
#include <unordered_map>

namespace Crane {

class OpenGLShader : public Shader {
public:
  OpenGLShader(
    const std::vector<std::string>& src, const std::vector<Shader::Type>& types,
    const std::string& name
  );
  OpenGLShader(const std::string& filename, const std::string& name);

  ~OpenGLShader() override;

  inline const std::string& getName() const override { return m_Name; }

  void destroy() override;
  void use() const override;

  uint32_t getUniformLocation(const std::string& name) const;
  void setUniform1i(const std::string& name, int v) const override;
  void setUniform1f(const std::string& name, float v) const override;
  void setUniform2f(const std::string& name, float v1, float v2) const override;
  void setUniform3f(const std::string& name, float v1, float v2, float v3) const override;
  void setUniformMat3f(const std::string& name, const float* v) const override;
  void setUniformMat4f(const std::string& name, const float* v) const override;
  void setUniformTexture(const std::string& name, const Texture * const tex) const override;

private:
  int m_Id;
  std::string m_Name;

  void fromSources
  (
    const std::vector<std::string>& src, const std::vector<Shader::Type>& types,
    const std::string& name
  );
  static int compileShaderSource(const std::string& src, Shader::Type type);

  struct Uniform {
    uint32_t location;
    Shader::Datatype type;
    Uniform() {};
    Uniform(uint32_t l, Shader::Datatype t)
      : location(l), type(t) {};
  };
  void queryUniforms();
  std::unordered_map<std::string, Uniform> m_Uniforms;

  static std::string nameFromFilename(const std::string& filename);
  static void getSourcesAndTypes
  (
    const std::string& file_contents,
    std::vector<std::string>& sources, std::vector<Shader::Type>& types
  );
};

}