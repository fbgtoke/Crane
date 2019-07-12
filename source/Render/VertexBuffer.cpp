#include "VertexBuffer.hpp"

#include <glad/glad.h>

namespace Crane {

VertexBuffer::VertexBuffer()
  : m_Id(GL_INVALID_VALUE) {}

VertexBuffer::~VertexBuffer()
{
  if (m_Id != GL_INVALID_VALUE)
  {
    destroy();
  }
}

void VertexBuffer::create(std::size_t size, void* data)
{
  glGenBuffers(1, &m_Id);
  glBindBuffer(GL_ARRAY_BUFFER, m_Id);
  glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

void VertexBuffer::destroy()
{
  glDeleteBuffers(1, &m_Id);
  m_Id = GL_INVALID_VALUE;
}

void VertexBuffer::bind() const
{
  glBindBuffer(GL_ARRAY_BUFFER, m_Id);
}

void VertexBuffer::unbind() const
{
  glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void VertexBuffer::setLayout(const BufferLayout& layout)
{
  m_Layout = layout;
}

}