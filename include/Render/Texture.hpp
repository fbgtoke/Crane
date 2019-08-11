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

#include <cstddef>
#include <cstdint>

namespace Crane {
  
class Texture {
public:
  static Texture* create(std::size_t width, std::size_t height, uint8_t* data);
  virtual void destroy() = 0;

  virtual void bind() const = 0;
  virtual void unbind() const = 0;

  virtual void setTextureUnit(uint32_t unit) = 0;

  virtual uint32_t getId() const = 0;
  virtual std::size_t getWidth() const = 0;
  virtual std::size_t getHeight() const = 0;

  virtual uint32_t getTextureUnit() const = 0;
};

}