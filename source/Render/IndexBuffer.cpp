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