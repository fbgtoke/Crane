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

#include "OpenGLFont.hpp"

#include "Render/Text.hpp"
#include "Render/VertexArray.hpp"
#include "Render/VertexBuffer.hpp"

namespace Crane {

class OpenGLText : public Text {
public:
  OpenGLText(const Font* font, const std::string& str);
  virtual ~OpenGLText() override;

  void destroy() override;

  void setFont(const Font* font) override;
  inline const Font* getFont() const override { return m_Font; }

  void setString(const std::string& str) override;
  inline const std::string& getString() const override { return m_String; }

  const VertexArray* getVertexArray() const { return m_VertexArray; }

private:
  const OpenGLFont* m_Font;
  std::string m_String;

  VertexArray* m_VertexArray;
  VertexBuffer* m_VertexBuffer;

  void updateBuffers();
};

}