#pragma once

#include <cstddef>
#include <iostream>
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