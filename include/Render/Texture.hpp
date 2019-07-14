#pragma once

#include <cstddef>

namespace Crane {
  
class Texture {
public:
  Texture();
  ~Texture();

  void create(std::size_t width, std::size_t height, unsigned char* data);
  void destroy();

  void bind() const;
  void unbind() const;

  void setTextureUnit(unsigned int unit);

  inline unsigned int getId() const { return m_Id; }
  inline std::size_t getWidth() const { return m_Width; }
  inline std::size_t getHeight() const { return m_Height; }

  inline unsigned int getTextureUnit() const { return m_TextureUnit; }

private:
  unsigned int m_Id;

  std::size_t m_Width;
  std::size_t m_Height;
  unsigned int m_TextureUnit;
};

}