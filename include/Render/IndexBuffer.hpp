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

namespace Crane {

class IndexBuffer {
public:
  IndexBuffer()
    : m_Count(0) {}
  virtual ~IndexBuffer() = default;

  static IndexBuffer* create(std::size_t size, unsigned int* data);
  virtual void destroy() = 0;

  virtual void bind() const = 0;
  virtual void unbind() const = 0;

  inline std::size_t getCount() const { return m_Count; }

protected:
  std::size_t m_Count;
};

}