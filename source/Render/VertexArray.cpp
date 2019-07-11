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

void VertexArray::bind() const
{
  glBindVertexArray(m_Id);
}

void VertexArray::unbind() const
{
  glBindVertexArray(0);
}

void VertexArray::addVertexBuffer(const VertexBuffer* buffer)
{
  glBindVertexArray(m_Id);
  buffer->bind();

  unsigned int index = 0;
  const BufferLayout& layout = buffer->getLayout();
  for (const auto& e : layout)
  {
    glEnableVertexAttribArray(index);
    glVertexAttribPointer(index,
      e.getCount(),
      BufferLayout::CraneDatatypeToOpenglDatatype(e.type),
      e.normalized ? GL_TRUE : GL_FALSE,
      layout.getStride(),
      (const void*)e.offset
    );
    index++;
  }

  m_VertexBuffers.push_back(buffer);
}

}