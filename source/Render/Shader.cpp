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

#include "Shader.hpp"

#include "Core/Log.hpp"

#include <glad/glad.h>

#include <cassert>
#include <fstream>
#include <streambuf>

namespace Crane {

Shader::Shader()
  : m_Type(ShaderType::Unknown), m_Id(GL_INVALID_VALUE), m_Compiled(false) {}

Shader::~Shader()
{
  if (m_Id != GL_INVALID_VALUE)
  {
    destroy();
  }
}

void Shader::create(ShaderType t)
{
  m_Type = t;

  switch (m_Type)
  {
  case ShaderType::Vertex:
    m_Id = glCreateShader(GL_VERTEX_SHADER);
    break;
  case ShaderType::Fragment:
    m_Id = glCreateShader(GL_FRAGMENT_SHADER);
    break;
  default:
    CRANE_LOG_FATAL("Unrecognized shader type");

  }
}

void Shader::destroy()
{
  glDeleteShader(m_Id);
  m_Id = GL_INVALID_VALUE;
}

bool Shader::compileFromFile(const std::string& file)
{
  assert(m_Id != GL_INVALID_VALUE);

  std::ifstream fstream(file);

  if (!fstream.is_open())
  {
    CRANE_LOG_WARN("Could not open shader file {0}", file);
    return false;
  }

  std::string src;
  src.assign(
    std::istreambuf_iterator<char>(fstream),
    std::istreambuf_iterator<char>()
  );
  return compileFromSource(src);
}

bool Shader::compileFromSource(const std::string& src)
{
  assert(m_Id != GL_INVALID_VALUE);

  const char* src_ptr = src.c_str();

  glShaderSource(m_Id, 1, &src_ptr, 0);
  glCompileShader(m_Id);

  int compiled = 0;
  glGetShaderiv(m_Id, GL_COMPILE_STATUS, &compiled);

  m_Compiled = (compiled != 0);

  if (!m_Compiled)
  {
    int max_length;
    glGetShaderiv(m_Id, GL_INFO_LOG_LENGTH, &max_length);

    std::string m_InfoLog = std::string(max_length, '\0');
    glGetShaderInfoLog(m_Id, max_length, &max_length, &m_InfoLog[0]);
    CRANE_LOG_ERROR("Error compiling shader\n\t{0}", m_InfoLog);
    return false;
  }

  return true;
}

std::size_t Shader::getDatatypeSize(ShaderDatatype t)
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