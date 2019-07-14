#include "Renderer.hpp"

#include <glad/glad.h>

namespace Crane {

void Renderer::render(const VertexArray& vao, const ShaderProgram& program)
{
  program.use();
  vao.bind();

  /* Placeholder */
  glDrawArrays(
    GL_TRIANGLES,
    0,
    3
  );
}

void Renderer::renderIndexed(
  const VertexArray& vao, const ShaderProgram& program,
  const Texture& texture
)
{
  program.use();
  vao.bind();
  texture.bind();

  glDrawElements(
    GL_TRIANGLES,
    vao.getIndexBuffer()->getCount(),
    GL_UNSIGNED_INT,
    nullptr
  );
}

}