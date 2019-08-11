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

#include "ObjReader.hpp"
#include "Core/Log.hpp"

#include <fstream>

namespace Crane {

bool ObjReader::read(
  const std::string& filename,
  std::vector<float>& data, std::vector<uint32_t>& indices
)
{
  /****************************************************************************/
  /* Open file                                                                */
  /****************************************************************************/
  std::ifstream fstream(filename);
  if (!fstream.is_open())
  {
    CRANE_LOG_WARN("Could not open OBJ mesh file {0}", filename);
    return false;
  }

  /****************************************************************************/
  /* Allocate arrays                                                          */
  /****************************************************************************/
  std::vector<Position> positions;
  std::vector<Texcoord> uvs;
  std::vector<Normal> normals;

  std::vector<Vertex> unique_vertices;

  /****************************************************************************/
  /* Read OBJ                                                                 */
  /****************************************************************************/
  std::string line;
  while (std::getline(fstream, line))
  {
    if (line.empty()) continue;

    std::stringstream sstream(line);

    std::string start;
    sstream >> start;

    /* Position */
    if (start == "v")
    {
      readPosition(sstream, positions);
    }
    /* Texcoord */
    else if (start == "vt")
    {
      readTexcoord(sstream, uvs);
    }
    /* Normal */
    else if (start == "vn")
    {
      readNormal(sstream, normals);
    }
    /* Face */
    else if (start == "f")
    {
      readFace(sstream, unique_vertices, indices);
    }
    /* Comment */
    else if (start == "#")
    {
      continue;
    }
    /* Unrecognized */
    else
    {
      CRANE_LOG_WARN("Unrecognized sequence in OBJ mesh file {0}", filename);
      return false;
    }
  }

  /****************************************************************************/
  /* Arrange data                                                             */
  /****************************************************************************/
  data.clear();
  data.reserve(unique_vertices.size() * 8);

  for (const Vertex& v : unique_vertices)
  {
    /* Positions */
    data.push_back(positions[v.p - 1].x);
    data.push_back(positions[v.p - 1].y);
    data.push_back(positions[v.p - 1].z);

    /* Texcoords */
    if (v.t != 0)
    {
      data.push_back(uvs[v.t - 1].u);
      data.push_back(uvs[v.t - 1].v);
    }
    else
    {
      data.push_back(0.f);
      data.push_back(0.f);
    }

    /* Normals */
    if (v.n != 0)
    {
      data.push_back(normals[v.n - 1].x);
      data.push_back(normals[v.n - 1].y);
      data.push_back(normals[v.n - 1].z);
    }
    else
    {
      data.push_back(0.f);
      data.push_back(0.f);
      data.push_back(0.f);
    }
  }

  return true;
}

void ObjReader::readPosition(
  std::stringstream& stream, std::vector<Position>& positions
)
{
  Position v;
  stream >> v.x >> v.y >> v.z;
  positions.push_back(v);
}

void ObjReader::readTexcoord(
  std::stringstream& stream, std::vector<Texcoord>& uvs
)
{
  Texcoord t;
  stream >> t.u >> t.v;
  uvs.push_back(t);
}

void ObjReader::readNormal(
  std::stringstream& stream, std::vector<Normal>& normals
)
{
  Normal n;
  stream >> n.x >> n.y >> n.z;
  normals.push_back(n);
}

void ObjReader::readFace(
  std::stringstream& stream, std::vector<Vertex>& unique_vertices,
  std::vector<uint32_t>& indices
)
{
  for (int i = 0; i < 3; ++i)
  {
    Vertex vertex;
    readVertex(stream, vertex);

    int index = findVertex(unique_vertices, vertex);
    if (index == -1)
    {
      unique_vertices.push_back(vertex);
      indices.push_back(unique_vertices.size() - 1);
    }
    else
    {
      indices.push_back((uint32_t)index);
    }
  }
}

void ObjReader::readVertex(
  std::stringstream& stream, Vertex& vertex
)
{
  char c;
  stream >> vertex.p >> c;

  c = stream.peek();
  if (std::isdigit(c))
  {
    stream >> vertex.t;
  }
  else
  {
    vertex.t = 0;
  }
  stream >> c;

  c = stream.peek();
  if (std::isdigit(c))
  {
    stream >> vertex.n;
  }
  else
  {
    vertex.n = 0;
  }
}

int ObjReader::findVertex(
  const std::vector<Vertex>& vertices, const Vertex& vertex
)
{
  for (uint32_t i = 0; i < vertices.size(); ++i)
  {
    if (vertices[i] == vertex)
    {
      return i;
    }
  }

  return -1;
}

}