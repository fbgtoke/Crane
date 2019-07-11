#pragma once

#include <cstddef>

namespace Crane {

typedef enum {
  Int, Int2, Int3, Int4,
  Float, Float2, Float3, Float4,
  Mat3, Mat4
} ShaderDatatype;

static std::size_t ShaderDatatypeSize(ShaderDatatype t)
{
  switch (t)
  {
    case ShaderDatatype::Int:    return sizeof(int) * 1;
    case ShaderDatatype::Int2:   return sizeof(int) * 2;
    case ShaderDatatype::Int3:   return sizeof(int) * 3;
    case ShaderDatatype::Int4:   return sizeof(int) * 4;
    case ShaderDatatype::Float:  return sizeof(float) * 1;
    case ShaderDatatype::Float2: return sizeof(float) * 2;
    case ShaderDatatype::Float3: return sizeof(float) * 3;
    case ShaderDatatype::Float4: return sizeof(float) * 4;
    case ShaderDatatype::Mat3:   return sizeof(float) * 3 * 3;
    case ShaderDatatype::Mat4:   return sizeof(float) * 4 * 4;
    default: return 0;
  }
}

}