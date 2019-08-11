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

#include "OpenGLTexture.hpp"
#include "OpenGLLog.hpp"

#include <glad/glad.h>

namespace Crane {

OpenGLTexture::OpenGLTexture(
  std::size_t width, std::size_t height, uint8_t* data
) : m_Id(GL_INVALID_VALUE), m_Width(width), m_Height(height), m_TextureUnit(0),
  m_Format(GL_RGB), m_Type(GL_UNSIGNED_BYTE),
  m_WrapS(GL_REPEAT), m_WrapT(GL_REPEAT),
  m_MinFilter(GL_LINEAR), m_MagFilter(GL_LINEAR)
{
  CRANE_GL_CALL(glGenTextures(1, &m_Id));
  CRANE_GL_CALL(glActiveTexture(GL_TEXTURE0 + m_TextureUnit));
  CRANE_GL_CALL(glBindTexture(GL_TEXTURE_2D, m_Id));
  
  CRANE_GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_WrapS));
  CRANE_GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_WrapT));

  CRANE_GL_CALL(
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_MinFilter)
  );
  CRANE_GL_CALL(
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_MagFilter)
  );

  CRANE_GL_CALL(glTexImage2D(
    GL_TEXTURE_2D,
    0, 
    m_Format,
    m_Width,
    m_Height,
    0,
    m_Format,
    m_Type,
    data
  ));
}

OpenGLTexture::~OpenGLTexture()
{
  if (m_Id != GL_INVALID_VALUE)
  {
    destroy();
  }
}

void OpenGLTexture::destroy()
{
  CRANE_GL_CALL(glDeleteTextures(1, &m_Id));
  m_Id = GL_INVALID_VALUE;
}

void OpenGLTexture::bind() const
{
  CRANE_GL_CALL(glActiveTexture(GL_TEXTURE0 + m_TextureUnit));
  CRANE_GL_CALL(glBindTexture(GL_TEXTURE_2D, m_Id));
}

void OpenGLTexture::unbind() const
{
  CRANE_GL_CALL(glBindTexture(GL_TEXTURE_2D, 0));
}

void OpenGLTexture::setTextureUnit(uint32_t unit)
{
  m_TextureUnit = unit;
}

void OpenGLTexture::setFormat(int format)
{
  m_Format = format;
}
void OpenGLTexture::setType(int type)
{
  m_Type = type;
}

void OpenGLTexture::setWrapS(int wrap)
{
  m_WrapS = wrap;
}
void OpenGLTexture::setWrapT(int wrap)
{
  m_WrapT = wrap;
}

void OpenGLTexture::setMinFilter(int filter)
{
  m_MinFilter = filter;
}
void OpenGLTexture::setMagFilter(int filter)
{
  m_MagFilter = filter;
}

uint32_t OpenGLTexture::getTextureUnit() const
{
  return m_TextureUnit;
}

/******************************************************************************/
/* Implementation of static methods from Texture class                        */
/******************************************************************************/
Texture* Texture::create(
  std::size_t width, std::size_t height, uint8_t* data
)
{
  return new OpenGLTexture(width, height, data);
}

}