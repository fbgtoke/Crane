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

#include "ShaderProgram.hpp"
#include "Core/Log.hpp"

#include <glad/glad.h>

#include <cassert>

namespace Crane {

ShaderProgram::ShaderProgram()
  : m_Id(GL_INVALID_VALUE), m_Linked(false) {}

ShaderProgram::~ShaderProgram()
{
  if (m_Id != GL_INVALID_VALUE)
  {
    destroy();
  }
}

void ShaderProgram::create()
{
  m_Id = CRANE_GL_CALL(glCreateProgram());
}

void ShaderProgram::destroy()
{
  CRANE_GL_CALL(glDeleteProgram(m_Id));
  m_Id = GL_INVALID_VALUE;
}

void ShaderProgram::attach(const Shader& shader) const
{
  CRANE_GL_CALL(glAttachShader(m_Id, shader.getId()));
}

void ShaderProgram::detach(const Shader& shader) const
{
  CRANE_GL_CALL(glDetachShader(m_Id, shader.getId()));
}

bool ShaderProgram::link()
{
  assert(m_Id != GL_INVALID_VALUE);

  CRANE_GL_CALL(glLinkProgram(m_Id));

  int linked = 0;
  CRANE_GL_CALL(glGetProgramiv(m_Id, GL_LINK_STATUS, &linked));

  m_Linked = (linked != 0);
  if (!m_Linked)
  {
    int max_length;
    CRANE_GL_CALL(glGetProgramiv(m_Id, GL_INFO_LOG_LENGTH, &max_length));

    m_InfoLog = std::string(max_length, '\0');
    CRANE_GL_CALL(
      glGetProgramInfoLog(m_Id, max_length, &max_length, &m_InfoLog[0])
    );

    return false;
  }

  queryUniforms();

  return true;
}

void ShaderProgram::use() const
{
  CRANE_GL_CALL(glUseProgram(m_Id));
}

unsigned int ShaderProgram::getUniformLocation(const std::string& name) const
{
  unsigned int location =
    CRANE_GL_CALL(glGetUniformLocation(m_Id, name.c_str()));
    
  return location;
}

/*
void ShaderProgram::setUniform1i(unsigned int location,
  int v
) const
{
  CRANE_GL_CALL(glUniform1i(location, v));
}

void ShaderProgram::setUniform1f(unsigned int location,
float v
) const
{
  CRANE_GL_CALL(glUniform1f(location, v));
}

void ShaderProgram::setUniform2f(unsigned int location, 
  float v1, float v2
) const
{
  CRANE_GL_CALL(glUniform2f(location, v1, v2));
}

void ShaderProgram::setUniform3f(unsigned int location, 
  float v1, float v2, float v3
) const
{
  CRANE_GL_CALL(glUniform3f(location, v1, v2, v3));
}

void ShaderProgram::setUniformMat3f(unsigned int location,
  const float* v
) const
{
  CRANE_GL_CALL(glUniformMatrix3fv(location, 1, GL_FALSE, v));
}

void ShaderProgram::setUniformMat4f(unsigned int location,
  const float* v
) const
{
  CRANE_GL_CALL(glUniformMatrix4fv(location, 1, GL_FALSE, v));
}
*/

void ShaderProgram::setUniform1i(const std::string name,
  int v
) const
{
  assert(m_Uniforms.contains(name));
  const Uniform& pos = m_Uniforms.at(name);
  CRANE_GL_CALL(glUniform1i(pos.location, v));
}

void ShaderProgram::setUniform1f(const std::string name,
float v
) const
{
  assert(m_Uniforms.contains(name));
  const Uniform& pos = m_Uniforms.at(name);
  CRANE_GL_CALL(glUniform1f(pos.location, v));
}

void ShaderProgram::setUniform2f(const std::string name, 
  float v1, float v2
) const
{
  assert(m_Uniforms.contains(name));
  const Uniform& pos = m_Uniforms.at(name);
  CRANE_GL_CALL(glUniform2f(pos.location, v1, v2));
}

void ShaderProgram::setUniform3f(const std::string name, 
  float v1, float v2, float v3
) const
{
  assert(m_Uniforms.contains(name));
  const Uniform& pos = m_Uniforms.at(name);
  CRANE_GL_CALL(glUniform3f(pos.location, v1, v2, v3));
}

void ShaderProgram::setUniformMat3f(const std::string name,
  const float* v
) const
{
  assert(m_Uniforms.contains(name));
  const Uniform& pos = m_Uniforms.at(name);
  CRANE_GL_CALL(glUniformMatrix3fv(pos.location, 1, GL_FALSE, v));
}

void ShaderProgram::setUniformMat4f(const std::string name,
  const float* v
) const
{
  assert(m_Uniforms.contains(name));
  const Uniform& pos = m_Uniforms.at(name);
  CRANE_GL_CALL(glUniformMatrix4fv(pos.location, 1, GL_FALSE, v));
}

ShaderDatatype toCrane(unsigned int type)
{
  switch (type)
  {
  case GL_INT:        return ShaderDatatype::Int;
  case GL_INT_VEC2:   return ShaderDatatype::Int2;
  case GL_INT_VEC3:   return ShaderDatatype::Int3;
  case GL_INT_VEC4:   return ShaderDatatype::Int4;
  case GL_FLOAT:      return ShaderDatatype::Float;
  case GL_FLOAT_VEC2: return ShaderDatatype::Float2;
  case GL_FLOAT_VEC3: return ShaderDatatype::Float3;
  case GL_FLOAT_VEC4: return ShaderDatatype::Float4;
  case GL_FLOAT_MAT3: return ShaderDatatype::Mat3;
  case GL_FLOAT_MAT4: return ShaderDatatype::Mat4;
  case GL_SAMPLER_2D: return ShaderDatatype::Tex;
  }

  CRANE_LOG_FATAL("Unsupported Uniform type");
  return ShaderDatatype::Int;
}

void ShaderProgram::queryUniforms()
{
  m_Uniforms.clear();

  int count;
  glGetProgramiv(m_Id, GL_ACTIVE_UNIFORMS, &count);

  const int max_length = 16;
  int length;
  int size;
  unsigned int type;
  char name[max_length];

  for (int i = 0; i < count; i++)
  {
    CRANE_GL_CALL(glGetActiveUniform(
      m_Id, (unsigned int)i,
      max_length, &length, &size, &type, name
    ));

    ShaderDatatype crane_type = toCrane(type);
    m_Uniforms[name] = Uniform(i, crane_type);
  }
}

}