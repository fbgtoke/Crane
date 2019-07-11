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