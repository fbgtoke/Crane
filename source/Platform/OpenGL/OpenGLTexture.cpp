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

namespace Crane {

OpenGLTexture::OpenGLTexture(
  std::size_t width, std::size_t height, uint8_t* data, format_t nch
) : m_Width(width), m_Height(height),
    m_Format(toOpenGL(nch)), m_Type(GL_UNSIGNED_BYTE)
{
  setData(m_Format, m_Type, (void*)data);
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

void OpenGLTexture::setData(uint32_t format, uint32_t type, void* data)
{
  CRANE_GL_CALL(glGenTextures(1, &m_Id));

  bind();

  CRANE_GL_CALL(glTexImage2D(
    GL_TEXTURE_2D,
    0, 
    format,
    m_Width,
    m_Height,
    0,
    format,
    type,
    data
  ));
}

void OpenGLTexture::bind() const
{
  CRANE_GL_CALL(glActiveTexture(GL_TEXTURE0 + m_TextureUnit));
  CRANE_GL_CALL(glBindTexture(GL_TEXTURE_2D, m_Id));

  CRANE_GL_CALL(
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, m_MinFilter)
  );

  CRANE_GL_CALL(
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, m_MagFilter)
  );

  CRANE_GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, m_WrapS));
  CRANE_GL_CALL(glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, m_WrapT));
}

void OpenGLTexture::unbind() const
{
  CRANE_GL_CALL(glBindTexture(GL_TEXTURE_2D, 0));
}

void OpenGLTexture::subImage(
  int x, int y, std::size_t w, std::size_t h, uint8_t* data
)
{
  CRANE_GL_CALL(
    glTexSubImage2D(GL_TEXTURE_2D, 0, x, y, w, h, m_Format, m_Type, data)
  );
}

int OpenGLTexture::toOpenGL(format_t ch)
{
  switch (ch)
  {
    case R:    return GL_RED;
    case RG :  return GL_RG;
    case RGB:  return GL_RGB;
    case RGBA: return GL_RGBA;
    case BGR:  return GL_BGR;
    case BGRA: return GL_BGRA;
  }

  CRANE_LOG_ERROR("Unknown texture format", ch);
  return 0;
}

/******************************************************************************/
/* Implementation of static methods from Texture class                        */
/******************************************************************************/
Texture* Texture::create(
  std::size_t width, std::size_t height, uint8_t* data, format_t ch
)
{
  return new OpenGLTexture(width, height, data, ch);
}

}