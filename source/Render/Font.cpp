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

#include "Font.hpp"
#include "Core/Log.hpp"
#include "Platform/OpenGL/OpenGLLog.hpp"

#include <glad/glad.h>
#include <GL/gl.h>

namespace Crane {

bool Font::loadFromFile(const std::string& filename)
{
  FT_Library ft;
  if (FT_Init_FreeType(&ft))
  {
    CRANE_LOG_FATAL("Could not initialize Freetype library");
  }

  FT_Face face;
  if (FT_New_Face(ft, filename.c_str(), 0, &face))
  {
    CRANE_LOG_WARN("Could not load font file {0}", filename);
    FT_Done_FreeType(ft);
    return false;
  }

  FT_Set_Pixel_Sizes(face, 0, 48);

  CRANE_GL_CALL(glPixelStorei(GL_UNPACK_ALIGNMENT, 1));
  for (char c = 'A'; c <= 'Z'; ++c)
  {
    if (FT_Load_Char(face, c, FT_LOAD_RENDER))
    {
      CRANE_LOG_WARN(
        "Could not load glyph '{0}' from font file {1}", c, filename
      );
      continue;
    }

    Texture* texture = new Texture();
    texture->setFormat(GL_RED);
    texture->setType(GL_UNSIGNED_BYTE);
    texture->setWrapS(GL_CLAMP_TO_EDGE);
    texture->setWrapT(GL_CLAMP_TO_EDGE);
    texture->create(
      face->glyph->bitmap.width,
      face->glyph->bitmap.rows,
      face->glyph->bitmap.buffer
    );

    Character character = {
      texture,
      face->glyph->bitmap.width,
      face->glyph->bitmap.rows,
      face->glyph->bitmap_left,
      face->glyph->bitmap_top,
      face->glyph->advance.x
    };

    m_Characters.insert(std::pair<char, Character>(c, character));
  }

  FT_Done_Face(face);
  FT_Done_FreeType(ft);

  return true;
}

}