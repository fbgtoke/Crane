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
  m_Id = glCreateProgram();
}

void ShaderProgram::destroy()
{
  glDeleteProgram(m_Id);
  m_Id = GL_INVALID_VALUE;
}

void ShaderProgram::attach(const Shader& shader) const
{
  glAttachShader(m_Id, shader.getId());
}

void ShaderProgram::detach(const Shader& shader) const
{
  glDetachShader(m_Id, shader.getId());
}

bool ShaderProgram::link()
{
  assert(m_Id != GL_INVALID_VALUE);

  glLinkProgram(m_Id);

  int linked = 0;
  glGetProgramiv(m_Id, GL_LINK_STATUS, &linked);

  m_Linked = (linked != 0);
  if (!m_Linked)
  {
    int max_length;
    glGetProgramiv(m_Id, GL_INFO_LOG_LENGTH, &max_length);

    m_InfoLog = std::string(max_length, '\0');
    glGetProgramInfoLog(m_Id, max_length, &max_length, &m_InfoLog[0]);

    return false;
  }

  return true;
}

void ShaderProgram::use() const
{
  glUseProgram(m_Id);
}

void ShaderProgram::setUniform1i(unsigned int location,
  int v
) const
{
  glUniform1i(location, v);
}

void ShaderProgram::setUniform1f(unsigned int location,
float v
) const
{
  glUniform1f(location, v);
}

void ShaderProgram::setUniform2f(unsigned int location, 
  float v1, float v2
) const
{
  glUniform2f(location, v1, v2);
}

void ShaderProgram::setUniform3f(unsigned int location, 
  float v1, float v2, float v3
) const
{
  glUniform3f(location, v1, v2, v3);
}

void ShaderProgram::setUniformMat3f(unsigned int location,
  float* v
) const
{
  glUniformMatrix3fv(location, 1, GL_FALSE, v);
}

void ShaderProgram::setUniformMat4f(unsigned int location,
  float* v
) const
{
  glUniformMatrix4fv(location, 1, GL_FALSE, v);
}

}