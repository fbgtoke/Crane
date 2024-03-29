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

#include "BmpReader.hpp"
#include "Core/Log.hpp"

#include <fstream>

namespace Crane {

bool BmpReader::read(
  const std::string& filename, std::size_t& width, std::size_t& height,
  std::vector<uint8_t>& data
)
{
  /****************************************************************************/
  /* Open file                                                                */
  /****************************************************************************/
  std::ifstream fstream(filename, std::ios::binary);
  if (!fstream.is_open())
  {
    CRANE_LOG_WARN("Could not open BMP texture file {0}", filename);
    return false;
  }

  /****************************************************************************/
  /* Read header                                                              */
  /****************************************************************************/
  char header[54];
  fstream.read(&header[0], 54);

  if (!fstream)
  {
    CRANE_LOG_WARN("Ill-formed BMP header in texture file {0}", filename);
    return false;
  }

  uint32_t offset;
  offset = *reinterpret_cast<uint32_t*>(&header[10]);
  width = *reinterpret_cast<uint32_t*>(&header[18]);
  height = *reinterpret_cast<uint32_t*>(&header[22]);

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
    CRANE_LOG_WARN("Ill-formed BMP body in texture file {0}", filename);
    return false;
  }

  /****************************************************************************/
  /* Convert BGR to RGB                                                       */
  /****************************************************************************/
  char tmp;
  for (uint32_t i = 0; i < data_size; i += 3)
  {
    tmp = data[i];
    data[i] = data[i+2];
    data[i+2] = tmp;
  }

  return true;
}

}