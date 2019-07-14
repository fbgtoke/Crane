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

#include "IndexBuffer.hpp"
#include "VertexBuffer.hpp"

#include <vector>

namespace Crane {

class VertexArray {
public:
  VertexArray();
  ~VertexArray();

  void create();
  void destroy();

  void bind() const;
  void unbind() const;

  void addVertexBuffer(const VertexBuffer* buffer);
  inline const std::vector<const VertexBuffer*>& getVertexBuffers() const
  {
    return m_VertexBuffers;
  }

  void setIndexBuffer(const IndexBuffer* buffer);
  inline const IndexBuffer* getIndexBuffer() const { return m_IndexBuffer; }

  inline unsigned int getId() const { return m_Id; }

private:
  unsigned int m_Id;

  std::vector<const VertexBuffer*> m_VertexBuffers;
  const IndexBuffer* m_IndexBuffer;
};

}