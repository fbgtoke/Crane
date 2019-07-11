#pragma once

namespace Crane {

class VertexArray {
public:
  VertexArray();
  ~VertexArray();

  void create();
  void destroy();
  
  void bind();
  void unbind();

  unsigned int getId() const;

private:
  unsigned int m_Id;
};

}