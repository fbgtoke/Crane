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