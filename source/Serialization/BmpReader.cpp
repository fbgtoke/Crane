#include "BmpReader.hpp"

#include <iostream>
#include <fstream>

namespace Crane {

bool BmpReader::read(
  const std::string& filename, std::size_t& width, std::size_t& height,
  std::vector<unsigned char>& data
)
{
  /****************************************************************************/
  /* Open file                                                                */
  /****************************************************************************/
  std::ifstream fstream(filename, std::ios::binary);
  if (!fstream.is_open())
  {
    std::cerr << "Error opening file " << filename << std::endl;
    return false;
  }

  /****************************************************************************/
  /* Read header                                                              */
  /****************************************************************************/
  char header[54];
  fstream.read(&header[0], 54);

  if (!fstream)
  {
    std::cerr << "Error while reading BMP header" << std::endl;
    return false;
  }

  unsigned int offset;
  offset = *reinterpret_cast<unsigned int*>(&header[10]);
  width = *reinterpret_cast<unsigned int*>(&header[18]);
  height = *reinterpret_cast<unsigned int*>(&header[22]);

  fstream.seekg(offset);

  /****************************************************************************/
  /* Read data                                                                */
  /****************************************************************************/
  std::size_t data_size = width * height * 3;

  data.clear();
  data.resize(data_size);
  fstream.read(reinterpret_cast<char*>(&data[0]), data.size());

  if (!fstream)
  {
    std::cerr << "Error while reading BMP body" << std::endl;
    return false;
  }

  /****************************************************************************/
  /* Convert BGR to RGB                                                       */
  /****************************************************************************/
  char tmp;
  for (unsigned int i = 0; i < data_size; i += 3)
  {
    tmp = data[i];
    data[i] = data[i+2];
    data[i+2] = tmp;
  }

  return true;
}

}