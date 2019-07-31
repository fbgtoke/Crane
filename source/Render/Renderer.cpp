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

#include "Renderer.hpp"
#include "Core/Log.hpp"

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
  program.setUniform1i("tex", texture.getTextureUnit());

  CRANE_GL_CALL(glDrawElements(
    GL_TRIANGLES,
    vao.getIndexBuffer()->getCount(),
    GL_UNSIGNED_INT,
    nullptr
  ));
}

}