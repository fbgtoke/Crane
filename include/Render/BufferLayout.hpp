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

#include <cstddef>
#include <initializer_list>
#include <string>
#include <vector>

namespace Crane {

struct BufferLayoutElement {
  std::string name;
  ShaderDatatype type;
  std::size_t size;
  std::size_t offset;
  bool normalized;

  BufferLayoutElement() {}
  BufferLayoutElement(
    const std::string& name, ShaderDatatype type, bool norm = false
  );

  uint32_t getCount() const
  {
    switch (type)
    {
      case ShaderDatatype::Int:    return 1;
      case ShaderDatatype::Int2:   return 2;
      case ShaderDatatype::Int3:   return 3;
      case ShaderDatatype::Int4:   return 4;
      case ShaderDatatype::Float:  return 1;
      case ShaderDatatype::Float2: return 2;
      case ShaderDatatype::Float3: return 3;
      case ShaderDatatype::Float4: return 4;
      case ShaderDatatype::Mat3:   return 3 * 3;
      case ShaderDatatype::Mat4:   return 4 * 4;
      default: return 0;
    }
  }
};

class BufferLayout {
public:
  BufferLayout();
  BufferLayout(const std::initializer_list<BufferLayoutElement>& elements);

  inline const std::vector<BufferLayoutElement>& getElements() const
  {
    return m_LayoutElements;
  }

  inline std::vector<BufferLayoutElement>::iterator begin()
  {
    return m_LayoutElements.begin();
  }

  inline std::vector<BufferLayoutElement>::iterator end()
  {
    return m_LayoutElements.end();
  }

  inline std::vector<BufferLayoutElement>::const_iterator begin() const
  {
    return m_LayoutElements.begin();
  }

  inline std::vector<BufferLayoutElement>::const_iterator end() const
  {
    return m_LayoutElements.end();
  }

  inline uint32_t getStride() const { return m_Stride; }

  static uint32_t toNativeDatatype(ShaderDatatype t);

private:
  std::vector<BufferLayoutElement> m_LayoutElements;
  uint32_t m_Stride;

  void computeOffsets();
};

}