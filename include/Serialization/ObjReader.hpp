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

#include <cstddef>
#include <string>
#include <sstream>
#include <vector>

namespace Crane {

class ObjReader {
public:
  static bool read(
    const std::string& filename,
    std::vector<float>& data, std::vector<unsigned int>& indices
  );

private:
  struct Position { float x, y, z; };
  struct Texcoord { float u, v; };
  struct Normal { float x, y, z; };
  struct Vertex {
    unsigned int p, t, n;

    bool operator==(const Vertex& v) const
    {
      return (p == v.p) && (t == v.t) && (n == v.n);
    }
  };

  static void readPosition(
    std::stringstream& stream, std::vector<Position>& positions
  );

  static void readTexcoord(
    std::stringstream& stream, std::vector<Texcoord>& uvs
  );

  static void readNormal(
    std::stringstream& stream, std::vector<Normal>& normals
  );

  static void readFace(
    std::stringstream& stream, std::vector<Vertex>& unique_vertices,
    std::vector<unsigned int>& indices
  );

  static void readVertex(
    std::stringstream& stream, Vertex& vertex
  );

  static int findVertex(
    const std::vector<Vertex>& vertices, const Vertex& vertex
  );
};

}