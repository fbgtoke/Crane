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

#include "OpenGLVertexArray.hpp"
#include "OpenGLLog.hpp"

#include <glad/glad.h>

namespace Crane {

OpenGLVertexArray::OpenGLVertexArray()
{
  CRANE_GL_CALL(glGenVertexArrays(1, &m_Id));
}

OpenGLVertexArray::~OpenGLVertexArray()
{
  if (m_Id != GL_INVALID_VALUE)
  {
    destroy();
  }
}

void OpenGLVertexArray::destroy()
{
  CRANE_GL_CALL(glDeleteVertexArrays(1, &m_Id));
  m_Id = GL_INVALID_VALUE;
}

void OpenGLVertexArray::bind() const
{
  CRANE_GL_CALL(glBindVertexArray(m_Id));
}

void OpenGLVertexArray::unbind() const
{
  CRANE_GL_CALL(glBindVertexArray(0));
}

void OpenGLVertexArray::addVertexBuffer(const VertexBuffer* buffer)
{
  CRANE_GL_CALL(glBindVertexArray(m_Id));
  buffer->bind();

  uint32_t index = 0;
  const BufferLayout& layout = buffer->getLayout();
  for (const auto& e : layout)
  {
    CRANE_GL_CALL(glEnableVertexAttribArray(index));
    CRANE_GL_CALL(glVertexAttribPointer(index,
      e.getCount(),
      BufferLayout::toNativeDatatype(e.type),
      e.normalized ? GL_TRUE : GL_FALSE,
      layout.getStride(),
      (const void*)e.offset
    ));
    index++;
  }

  m_VertexBuffers.push_back(buffer);
}

void OpenGLVertexArray::setIndexBuffer(const IndexBuffer* buffer)
{
  CRANE_GL_CALL(glBindVertexArray(m_Id));
  buffer->bind();
  
  m_IndexBuffer = buffer;
}

/******************************************************************************/
/* Implementation of static methods from VertexArray class                    */
/******************************************************************************/
VertexArray* VertexArray::create()
{
  return new OpenGLVertexArray();
}

}