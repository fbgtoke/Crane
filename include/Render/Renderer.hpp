#pragma once

#include "ShaderProgram.hpp"
#include "VertexArray.hpp"

namespace Crane {

class Renderer {
public:
  static void render(const VertexArray& vao, const ShaderProgram& program);
  static void renderIndexed(const VertexArray& vao, const ShaderProgram& program);
};

}