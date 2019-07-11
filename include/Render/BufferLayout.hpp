#pragma once

#include "ShaderDatatype.hpp"

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

  unsigned int getCount() const
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

  inline unsigned int getStride() const { return m_Stride; }

  static unsigned int CraneDatatypeToOpenglDatatype(ShaderDatatype t);

private:
  std::vector<BufferLayoutElement> m_LayoutElements;
  unsigned int m_Stride;

  void computeOffsets();
};

}