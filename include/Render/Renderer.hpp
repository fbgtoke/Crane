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

#include "Font.hpp"
#include "Text.hpp"
#include "Texture.hpp"
#include "Shader.hpp"
#include "VertexArray.hpp"

namespace Crane {

class Renderer {
public:
  static void clear();

  static void render(
    const VertexArray * const vao, const Shader * const program
  );

  static void renderIndexed(
    const VertexArray * const vao, const Shader * const program,
    const Texture * const texture
  );

  static void render(const Shader * const program, const Text * text);
};

}