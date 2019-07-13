#include "ObjReader.hpp"

#include <fstream>

namespace Crane {

bool ObjReader::read(
  const std::string& filename,
  std::vector<float>& data, std::vector<unsigned int>& indices
)
{
  /****************************************************************************/
  /* Open file                                                                */
  /****************************************************************************/
  std::ifstream fstream(filename);
  if (!fstream.is_open())
  {
    std::cerr << "Error opening file " << filename << std::endl;
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
    /* Unrecognized */
    else
    {
      std::cerr << "Error while reading file " << filename << std::endl;
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
  std::vector<unsigned int>& indices
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
      indices.push_back((unsigned int)index);
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
  for (unsigned int i = 0; i < vertices.size(); ++i)
  {
    if (vertices[i] == vertex)
    {
      return i;
    }
  }

  return -1;
}

}