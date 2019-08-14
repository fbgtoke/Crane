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

#include "OpenGLText.hpp"

#include "Core/Log.hpp"

namespace Crane {

OpenGLText::OpenGLText(const Font* font, const std::string& str)
  : m_Font(dynamic_cast<const OpenGLFont*>(font)), m_String(str),
    m_VertexArray(nullptr), m_VertexBuffer(nullptr)
{
  updateBuffers();
}

OpenGLText::~OpenGLText()
{
  destroy();
}

void OpenGLText::destroy()
{
  if (m_VertexArray != nullptr)
  {
    m_VertexArray->destroy();
    m_VertexArray = nullptr;
  }

  if (m_VertexBuffer != nullptr)
  {
    m_VertexBuffer->destroy();
    m_VertexBuffer = nullptr;
  }
}

void OpenGLText::setFont(const Font* font)
{
  m_Font = dynamic_cast<const OpenGLFont*>(font);
  updateBuffers();
}

void OpenGLText::setString(const std::string& str)
{
  m_String = str;
  updateBuffers();
}

void OpenGLText::updateBuffers()
{
  destroy();

  std::vector<float> data;
  std::size_t size;

  float cur_offsetX = 0.f;
  for (std::size_t i = 0; i < m_String.size(); ++i)
  {
    char c = m_String[i];
    const OpenGLFont::Character& uvs = m_Font->getCharacter(c);

    float atlas_width = m_Font->getTextureAtlas()->getWidth();
    float atlas_height = m_Font->getTextureAtlas()->getHeight();

    float v[] =
    {
      //                  x,           y,                       u,                        v
    cur_offsetX +         0,  uvs.height, (uvs.offsetX +       0.f)/atlas_width, (uvs.offsetY + uvs.height)/atlas_height,
    cur_offsetX +         0,           0, (uvs.offsetX +       0.f)/atlas_width, (uvs.offsetY +        0.f)/atlas_height,
    cur_offsetX + uvs.width,           0, (uvs.offsetX + uvs.width)/atlas_width, (uvs.offsetY +        0.f)/atlas_height,
    cur_offsetX +         0,  uvs.height, (uvs.offsetX +       0.f)/atlas_width, (uvs.offsetY + uvs.height)/atlas_height,
    cur_offsetX + uvs.width,           0, (uvs.offsetX + uvs.width)/atlas_width, (uvs.offsetY +        0.f)/atlas_height,
    cur_offsetX + uvs.width,  uvs.height, (uvs.offsetX + uvs.width)/atlas_width, (uvs.offsetY + uvs.height)/atlas_height
    };
    cur_offsetX += uvs.width;

    data.insert(data.end(), v, v+24);
  }
  size = data.size() * sizeof(float);

  m_VertexArray = VertexArray::create();
  m_VertexArray->bind();

  m_VertexBuffer = VertexBuffer::create(size, &data[0]);
  m_VertexBuffer->setLayout({
    { "position", Crane::ShaderDatatype::Float2 },
    { "uvs", Crane::ShaderDatatype::Float2 }
  });
  m_VertexArray->addVertexBuffer(m_VertexBuffer);
}

/******************************************************************************/
/* Implementation of static methods from Text class                           */
/******************************************************************************/
Text* Text::create(const Font* font, const std::string& str)
{
  return new OpenGLText(font, str);
}

}