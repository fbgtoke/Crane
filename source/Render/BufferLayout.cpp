#include "BufferLayout.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Crane {

BufferLayoutElement::BufferLayoutElement(
  const std::string& name, ShaderDatatype type, bool norm
) : name(name), type(type), size(ShaderDatatypeSize(type)), offset(0),
    normalized(norm) {}

BufferLayout::BufferLayout()
  : m_LayoutElements(), m_Stride(0) {}

BufferLayout::BufferLayout(
  const std::initializer_list<BufferLayoutElement>& elements
)
  : m_LayoutElements(elements), m_Stride(0)
{
  computeOffsets();
}

void BufferLayout::computeOffsets()
{
  m_Stride = 0;

  for (BufferLayoutElement& e : m_LayoutElements)
  {
    e.offset = m_Stride;
    m_Stride += e.size;
  }
}

unsigned int BufferLayout::CraneDatatypeToOpenglDatatype(ShaderDatatype t)
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