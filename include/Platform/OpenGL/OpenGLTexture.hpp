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

#pragma once

#include "Render/Texture.hpp"

#include <glad/glad.h>

#include <cstdint>

namespace Crane {
  
class OpenGLTexture : public Texture {
public:
  OpenGLTexture(
    std::size_t width, std::size_t height, uint8_t* data,
    format_t ch
  );
  ~OpenGLTexture();

  void destroy() override;


  void bind() const override;
  void unbind() const override;

  inline void setTextureUnit(uint32_t unit) override { m_TextureUnit = unit; }
  inline uint32_t getTextureUnit() const override { return m_TextureUnit; }

  inline void setWrapS(int wrap) { m_WrapS = wrap; };
  inline void setWrapT(int wrap) { m_WrapT = wrap; };

  inline void setMinFilter(int filter) { m_MinFilter = filter; };
  inline void setMagFilter(int filter) { m_MagFilter = filter; };

  inline uint32_t getId() const override { return m_Id; }
  inline std::size_t getWidth() const override { return m_Width; }
  inline std::size_t getHeight() const override { return m_Height; }

  void subImage(
    int x, int y, std::size_t w, std::size_t h, uint8_t* data
  ) override;
private:
  uint32_t m_Id = GL_INVALID_VALUE;
  uint32_t m_TextureUnit = 0;

  std::size_t m_Width;
  std::size_t m_Height;

  static int toOpenGL(format_t ch);

  int m_Format;
  int m_Type;

  int m_WrapS = GL_REPEAT;
  int m_WrapT = GL_REPEAT;

  int m_MinFilter = GL_LINEAR;
  int m_MagFilter = GL_LINEAR;

  void setData(uint32_t format, uint32_t type, void* data);
};

}