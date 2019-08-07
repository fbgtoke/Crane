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

#include "Render/VertexArray.hpp"

namespace Crane {

class OpenGLVertexArray : public VertexArray {
public:
  OpenGLVertexArray();
  virtual ~OpenGLVertexArray() override;

  void destroy() override;

  void bind() const override;
  void unbind() const override;

  void addVertexBuffer(const VertexBuffer* buffer) override;
  void setIndexBuffer(const IndexBuffer* buffer) override;

  inline unsigned int getId() const { return m_Id; }

private:
  unsigned int m_Id;
};

}