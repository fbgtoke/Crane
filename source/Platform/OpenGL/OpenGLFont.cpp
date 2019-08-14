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

#include "OpenGLFont.hpp"
#include "OpenGLLog.hpp"
#include "OpenGLTexture.hpp"

#include "Core/Log.hpp"

#include <glad/glad.h>
#include <GL/gl.h>

#include <ft2build.h>
#include FT_FREETYPE_H

#include <algorithm>

namespace Crane {

OpenGLFont::OpenGLFont(const std::string& filename)
  : m_Atlas(nullptr)
{
  FT_Library ft;
  if (FT_Init_FreeType(&ft))
  {
    CRANE_LOG_FATAL("Could not initialize Freetype library");
  }

  FT_Face face;
  if (FT_New_Face(ft, filename.c_str(), 0, &face))
  {
    FT_Done_FreeType(ft);
    CRANE_LOG_FATAL("Could not load font file {0}", filename);
  }

  FT_Set_Pixel_Sizes(face, 0, 48);

  uint32_t max_width = 0;
  uint32_t max_height = 0;

  // To do.. All this section needs to be cleaned up
  std::vector<char> alphabet;
  for (char c = 'A'; c <= 'Z'; ++c) alphabet.push_back(c);
  for (char c = 'a'; c <= 'z'; ++c) alphabet.push_back(c);
  for (char c = '0'; c <= '9'; ++c) alphabet.push_back(c);
  alphabet.push_back('.');
  alphabet.push_back('(');
  alphabet.push_back(')');

  /* Allocate empty texture */
  //for (char c = 'A'; c <= 'Z'; ++c)
  for (char c : alphabet)
  {
    if (FT_Load_Char(face, c, FT_LOAD_RENDER))
    {
      CRANE_LOG_WARN("Could not load glyph", c, "from font file", filename);
      continue;
    }

    max_width += face->glyph->bitmap.width;
    max_height = std::max(max_height, face->glyph->bitmap.rows);
  }

  m_Atlas = Texture::create(max_width, max_height, nullptr, Texture::R);
  // TODO: expand Texture API to avoid this cast
  OpenGLTexture* ogl_texture = dynamic_cast<OpenGLTexture*>(m_Atlas);
    ogl_texture->setWrapS(GL_CLAMP_TO_EDGE);
    ogl_texture->setWrapT(GL_CLAMP_TO_EDGE);

  /* Populate atlas */
  uint32_t cur_x = 0;
  CRANE_GL_CALL(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));

  //for (char c = 'A'; c <= 'Z'; ++c)
  for (char c : alphabet)
  {
    if (FT_Load_Char(face, c, FT_LOAD_RENDER))
    {
      CRANE_LOG_WARN("Could not load glyph", c, "from font file", filename);
      continue;
    }

    m_Atlas->subImage(
      cur_x,
      0,
      face->glyph->bitmap.width,
      face->glyph->bitmap.rows,
      face->glyph->bitmap.buffer
    );

    Character character = {
      cur_x,
      0,
      face->glyph->bitmap.width,
      face->glyph->bitmap.rows,
      face->glyph->bitmap_left,
      face->glyph->bitmap_top,
      face->glyph->advance.x
    };
    m_Characters.insert(std::pair<char, Character>(c, character));

    cur_x += face->glyph->bitmap.width;
  }

  FT_Done_Face(face);
  FT_Done_FreeType(ft);
}

/******************************************************************************/
/* Implementation of static methods from Font class                           */
/******************************************************************************/
Font* Font::create(const std::string& filename)
{
  return new OpenGLFont(filename);
}

}