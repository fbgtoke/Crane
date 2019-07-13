#pragma once

#include <cstddef>

namespace Crane {

class IndexBuffer {
public:
  IndexBuffer();
  ~IndexBuffer();

  void create(std::size_t size, unsigned int* data);
  void destroy();

  void bind() const;
  void unbind() const;

  inline unsigned int getId() const { return m_Id; }
  inline std::size_t getCount() const { return m_Count; }

private:
  unsigned int m_Id;
  std::size_t m_Count;
};

}