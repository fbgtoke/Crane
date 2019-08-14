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

#include "Font.hpp"

#include <string>

namespace Crane {

class Text {
public:
  Text() = default;
  virtual ~Text() = default;

  static Text* create(const Font* font = nullptr, const std::string& str = "");
  virtual void destroy() = 0;

  virtual void setFont(const Font* font) = 0;
  virtual const Font* getFont() const = 0;

  virtual void setString(const std::string& str) = 0;
  virtual const std::string& getString() const = 0;
};

}