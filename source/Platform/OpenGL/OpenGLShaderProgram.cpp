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

#include "OpenGLShaderProgram.hpp"
#include "OpenGLShader.hpp"
#include "Core/Log.hpp"

#include <glad/glad.h>

#include <cassert>

namespace Crane {

OpenGLShaderProgram::OpenGLShaderProgram()
{
  m_Id = CRANE_GL_CALL(glCreateProgram());
}

OpenGLShaderProgram::~OpenGLShaderProgram()
{
  if (m_Id != GL_INVALID_VALUE)
  {
    destroy();
  }
}

void OpenGLShaderProgram::destroy()
{
  CRANE_GL_CALL(glDeleteProgram(m_Id));
  m_Id = GL_INVALID_VALUE;
}

void OpenGLShaderProgram::attach(const Shader * const shader) const
{
  const OpenGLShader * const ogl_shader =
    dynamic_cast<const OpenGLShader * const >(shader);

  CRANE_GL_CALL(glAttachShader(m_Id, ogl_shader->getId()));
}

void OpenGLShaderProgram::detach(const Shader * const shader) const
{
  const OpenGLShader * const ogl_shader =
    dynamic_cast<const OpenGLShader * const >(shader);

  CRANE_GL_CALL(glDetachShader(m_Id, ogl_shader->getId()));
}

bool OpenGLShaderProgram::link()
{
  assert(m_Id != GL_INVALID_VALUE);

  CRANE_GL_CALL(glLinkProgram(m_Id));

  int linked = 0;
  CRANE_GL_CALL(glGetProgramiv(m_Id, GL_LINK_STATUS, &linked));

  if (!linked)
  {
    int max_length;
    CRANE_GL_CALL(glGetProgramiv(m_Id, GL_INFO_LOG_LENGTH, &max_length));

    std::string log = std::string(max_length, '\0');
    CRANE_GL_CALL(
      glGetProgramInfoLog(m_Id, max_length, &max_length, &log[0])
    );

    CRANE_LOG_WARN(log);

    return false;
  }

  queryUniforms();

  return true;
}

void OpenGLShaderProgram::use() const
{
  CRANE_GL_CALL(glUseProgram(m_Id));
}

unsigned int OpenGLShaderProgram::getUniformLocation(const std::string& name) const
{
  unsigned int location =
    CRANE_GL_CALL(glGetUniformLocation(m_Id, name.c_str()));
    
  return location;
}

void OpenGLShaderProgram::setUniform1i(const std::string name,
  int v
) const
{
  assert(m_Uniforms.contains(name));
  const Uniform& uniform = m_Uniforms.at(name);
  assert(uniform.type == ShaderDatatype::Int);
  CRANE_GL_CALL(glUniform1i(uniform.location, v));
}

void OpenGLShaderProgram::setUniform1f(const std::string name,
float v
) const
{
  assert(m_Uniforms.contains(name));
  const Uniform& uniform = m_Uniforms.at(name);
  assert(uniform.type == ShaderDatatype::Float);
  CRANE_GL_CALL(glUniform1f(uniform.location, v));
}

void OpenGLShaderProgram::setUniform2f(const std::string name, 
  float v1, float v2
) const
{
  assert(m_Uniforms.contains(name));
  const Uniform& uniform = m_Uniforms.at(name);
  assert(uniform.type == ShaderDatatype::Float2);
  CRANE_GL_CALL(glUniform2f(uniform.location, v1, v2));
}

void OpenGLShaderProgram::setUniform3f(const std::string name, 
  float v1, float v2, float v3
) const
{
  assert(m_Uniforms.contains(name));
  const Uniform& uniform = m_Uniforms.at(name);
  assert(uniform.type == ShaderDatatype::Float3);
  CRANE_GL_CALL(glUniform3f(uniform.location, v1, v2, v3));
}

void OpenGLShaderProgram::setUniformMat3f(const std::string name,
  const float* v
) const
{
  assert(m_Uniforms.contains(name));
  const Uniform& uniform = m_Uniforms.at(name);
  assert(uniform.type == ShaderDatatype::Mat3);
  CRANE_GL_CALL(glUniformMatrix3fv(uniform.location, 1, GL_FALSE, v));
}

void OpenGLShaderProgram::setUniformMat4f(const std::string name,
  const float* v
) const
{
  assert(m_Uniforms.contains(name));
  const Uniform& uniform = m_Uniforms.at(name);
  assert(uniform.type == ShaderDatatype::Mat4);
  CRANE_GL_CALL(glUniformMatrix4fv(uniform.location, 1, GL_FALSE, v));
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

void OpenGLShaderProgram::queryUniforms()
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

/******************************************************************************/
/* Implementation of static methods from ShaderProgram class                  */
/******************************************************************************/
ShaderProgram* ShaderProgram::create()
{
  return new OpenGLShaderProgram();
}

}