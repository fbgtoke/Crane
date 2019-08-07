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

#include "Render/Renderer.hpp"
#include "OpenGLLog.hpp"

#include <glad/glad.h>

namespace Crane {

void Renderer::clear()
{
  CRANE_GL_CALL(glClearColor(1.f, 0.f, 1.f, 1.f));
  CRANE_GL_CALL(glEnable(GL_BLEND));
  CRANE_GL_CALL(glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA));

  CRANE_GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
  CRANE_GL_CALL(glClear(GL_DEPTH_BUFFER_BIT));
}

void Renderer::render(
  const VertexArray * const vao, const ShaderProgram * const program
)
{
  program->use();
  vao->bind();

  /* Placeholder */
  glDrawArrays(
    GL_TRIANGLES,
    0,
    3
  );
}

void Renderer::renderIndexed(
  const VertexArray * const vao, const ShaderProgram * const program,
  const Texture& texture
)
{
  program->use();

  vao->bind();

  texture.bind();
  /* To do: replace hardcoded "tex" */
  program->setUniformTexture("tex", &texture);

  CRANE_GL_CALL(glDrawElements(
    GL_TRIANGLES,
    vao->getIndexBuffer()->getCount(),
    GL_UNSIGNED_INT,
    nullptr
  ));
}

}