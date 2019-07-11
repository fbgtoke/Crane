#include "VertexArray.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Crane {

VertexArray::VertexArray()
  : m_Id(GL_INVALID_VALUE) {}

VertexArray::~VertexArray()
{
  if (m_Id != GL_INVALID_VALUE)
  {
    destroy();
  }
}

void VertexArray::create()
{
  glGenVertexArrays(1, &m_Id);
}

void VertexArray::destroy()
{
  glDeleteVertexArrays(1, &m_Id);
  m_Id = GL_INVALID_VALUE;
}

void VertexArray::bind()
{
  glBindVertexArray(m_Id);
}

void VertexArray::unbind()
{
  glBindVertexArray(0);
}

unsigned int VertexArray::getId() const
{
  return m_Id;
}

}