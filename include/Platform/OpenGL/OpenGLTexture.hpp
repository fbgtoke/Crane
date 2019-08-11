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

#include <cstdint>

namespace Crane {
  
class OpenGLTexture : public Texture {
public:
  OpenGLTexture(std::size_t width, std::size_t height, uint8_t* data);
  ~OpenGLTexture();

  void destroy() override;

  void bind() const override;
  void unbind() const override;

  void setTextureUnit(uint32_t unit) override;

  void setFormat(int format);
  void setType(int type);

  void setWrapS(int wrap);
  void setWrapT(int wrap);

  void setMinFilter(int filter);
  void setMagFilter(int filter);

  inline uint32_t getId() const override { return m_Id; }
  inline std::size_t getWidth() const override { return m_Width; }
  inline std::size_t getHeight() const override { return m_Height; }

  uint32_t getTextureUnit() const override;

private:
  uint32_t m_Id;

  std::size_t m_Width;
  std::size_t m_Height;
  uint32_t m_TextureUnit;

  int m_Format;
  int m_Type;

  int m_WrapS;
  int m_WrapT;

  int m_MinFilter;
  int m_MagFilter;
};

}