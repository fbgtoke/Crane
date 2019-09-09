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

#include "Render/Font.hpp"
#include "Render/Texture.hpp"

#include <map>
#include <vector>

namespace Crane {

class OpenGLFont : public Font {
public:
  OpenGLFont(const std::string& filename);

  inline Texture* getTextureAtlas() const override
  {
    return m_Atlas;
  }

  typedef struct {
    uint32_t offsetX;
    uint32_t offsetY;
    uint32_t width;
    uint32_t height;
    int bearingX;
    int bearingY;
    long int advance;
  } Character;
  inline const Character& getCharacter(char c) const
  {
    return m_Characters.at(c);
  }
  
private:
  Texture* m_Atlas;
  std::map<char, Character> m_Characters;

  static void getAlphabet(std::vector<char>& alphabet);
};

}