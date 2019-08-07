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

#include "OpenGLVertexBuffer.hpp"
#include "Core/Log.hpp"

#include <glad/glad.h>

namespace Crane {

OpenGLVertexBuffer::OpenGLVertexBuffer(std::size_t size, void* data)
{
  CRANE_GL_CALL(glGenBuffers(1, &m_Id));
  CRANE_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_Id));
  CRANE_GL_CALL(glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW));
}

OpenGLVertexBuffer::~OpenGLVertexBuffer()
{
  if (m_Id != GL_INVALID_VALUE)
  {
    destroy();
  }
}

void OpenGLVertexBuffer::destroy()
{
  CRANE_GL_CALL(glDeleteBuffers(1, &m_Id));
  m_Id = GL_INVALID_VALUE;
}

void OpenGLVertexBuffer::bind() const
{
  CRANE_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, m_Id));
}

void OpenGLVertexBuffer::unbind() const
{
  CRANE_GL_CALL(glBindBuffer(GL_ARRAY_BUFFER, 0));
}

/******************************************************************************/
/* Implementation of static methods from VertexBuffer class                   */
/******************************************************************************/
VertexBuffer* VertexBuffer::create(std::size_t size, void* data)
{
  return new OpenGLVertexBuffer(size, data);
}

}