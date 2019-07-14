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