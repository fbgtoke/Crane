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

#include "BufferLayout.hpp"

#include <cstddef>

namespace Crane {

class VertexBuffer {
public:
  VertexBuffer();
  ~VertexBuffer();

  void create(std::size_t size, void* data);
  void destroy();

  void bind() const;
  void unbind() const;

  void setLayout(const BufferLayout& layout);

  inline unsigned int getId() const { return m_Id; }
  inline const BufferLayout& getLayout() const { return m_Layout; }

private:
  unsigned int m_Id;
  BufferLayout m_Layout;
};

}