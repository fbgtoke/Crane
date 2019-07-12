#include "Renderer.hpp"

#include <glad/glad.h>

namespace Crane {

void Renderer::render(const VertexArray& vao, const ShaderProgram& program)
{
  program.use();
  vao.bind();

  /* Placeholder */
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

}