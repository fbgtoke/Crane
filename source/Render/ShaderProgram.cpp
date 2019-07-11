#include "ShaderProgram.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

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

}