#include "IndexBuffer.hpp"

#include <glad/glad.h>

namespace Crane {

IndexBuffer::IndexBuffer()
  : m_Id(GL_INVALID_VALUE), m_Count(0) {}

IndexBuffer::~IndexBuffer()
{
  if (m_Id != GL_INVALID_VALUE)
  {
    destroy();
  }
}

void IndexBuffer::create(std::size_t size, unsigned int* data)
{
  glGenBuffers(1, &m_Id);
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);

  m_Count = size / sizeof(unsigned int);
}

void IndexBuffer::destroy()
{
  glDeleteBuffers(1, &m_Id);
  m_Id = GL_INVALID_VALUE;
}

void IndexBuffer::bind() const
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
}

void IndexBuffer::unbind() const
{
  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

}