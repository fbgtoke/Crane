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

#include "Texture.hpp"

#include <glad/glad.h>

namespace Crane {

Texture::Texture()
  : m_Id(GL_INVALID_VALUE), m_Width(0), m_Height(0), m_TextureUnit(0) {}

Texture::~Texture()
{
  if (m_Id != GL_INVALID_VALUE)
  {
    destroy();
  }
}

void Texture::create(std::size_t width, std::size_t height, unsigned char* data)
{
  m_Width = width;
  m_Height = height;

  glGenTextures(1, &m_Id);
  glBindTexture(GL_TEXTURE_2D, m_Id);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(
    GL_TEXTURE_2D,
    0, 
    GL_RGB,
    m_Width,
    m_Height,
    0,
    GL_RGB,
    GL_UNSIGNED_BYTE,
    data
  );
}

void Texture::destroy()
{
  glDeleteTextures(1, &m_Id);
  m_Id = GL_INVALID_VALUE;
}

void Texture::bind() const
{
  glActiveTexture(GL_TEXTURE0 + m_TextureUnit);
  glBindTexture(GL_TEXTURE_2D, m_Id);
}

void Texture::unbind() const
{
  glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::setTextureUnit(unsigned int unit)
{
  m_TextureUnit = unit;
}

}