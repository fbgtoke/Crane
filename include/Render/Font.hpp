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

#include "Texture.hpp"

#include <ft2build.h>
#include FT_FREETYPE_H

#include <map>
#include <string>

namespace Crane {

class Font {
public:
  bool loadFromFile(const std::string& filename);

  inline Texture* getCharacterTexture(char c) const
  {
    return m_Characters.at(c).texture;
  }

private:
  struct Character {
    Texture* texture;
    unsigned int width;
    unsigned int height;
    int bearingX;
    int bearingY;
    int advance;
  };

  std::map<char, Character> m_Characters;
};

}