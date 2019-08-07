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

#include "OpenGLIndexBuffer.hpp"
#include "Core/Log.hpp"

#include <glad/glad.h>

namespace Crane {

OpenGLIndexBuffer::OpenGLIndexBuffer(std::size_t size, unsigned int* data)
{
  CRANE_GL_CALL(glGenBuffers(1, &m_Id));
  CRANE_GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id));

  CRANE_GL_CALL(
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW)
  );

  m_Count = size / sizeof(unsigned int);
}

OpenGLIndexBuffer::~OpenGLIndexBuffer()
{
  if (m_Id != GL_INVALID_VALUE)
  {
    destroy();
  }
}

void OpenGLIndexBuffer::destroy()
{
  CRANE_GL_CALL(glDeleteBuffers(1, &m_Id));
  m_Id = GL_INVALID_VALUE;
}

void OpenGLIndexBuffer::bind() const
{
  CRANE_GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id));
}

void OpenGLIndexBuffer::unbind() const
{
  CRANE_GL_CALL(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}

/******************************************************************************/
/* Implementation of static methods from IndexBuffer class                    */
/******************************************************************************/
IndexBuffer* IndexBuffer::create(std::size_t size, unsigned int* data)
{
  return new OpenGLIndexBuffer(size, data);
}

}