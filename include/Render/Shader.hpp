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

#include <string>

namespace Crane {

typedef enum {
  Int, Int2, Int3, Int4,
  Float, Float2, Float3, Float4,
  Mat3, Mat4,
  Tex
} ShaderDatatype;

class Shader {
public:
  typedef enum {
    Unknown, Vertex, Fragment
  } ShaderType;

  Shader() = default;
  virtual ~Shader() = default;
  virtual void destroy() = 0;
  
  static Shader* create(ShaderType t, const std::string& src);
  static std::size_t getDatatypeSize(ShaderDatatype t);
};

}