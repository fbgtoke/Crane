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

#include "BufferLayout.hpp"

#include <glad/glad.h>

namespace Crane {

uint32_t BufferLayout::toNativeDatatype(ShaderDatatype t)
{
  switch (t)
  {
    case ShaderDatatype::Int:    return GL_INT;
    case ShaderDatatype::Int2:   return GL_INT;
    case ShaderDatatype::Int3:   return GL_INT;
    case ShaderDatatype::Int4:   return GL_INT;
    case ShaderDatatype::Float:  return GL_FLOAT;
    case ShaderDatatype::Float2: return GL_FLOAT;
    case ShaderDatatype::Float3: return GL_FLOAT;
    case ShaderDatatype::Float4: return GL_FLOAT;
    case ShaderDatatype::Mat3:   return GL_FLOAT;
    case ShaderDatatype::Mat4:   return GL_FLOAT;
    default: return GL_INVALID_VALUE;
  }
}

}