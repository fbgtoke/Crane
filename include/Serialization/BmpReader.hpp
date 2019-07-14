#pragma once

#include <cstddef>
#include <string>
#include <vector>

namespace Crane {

class BmpReader {
public:
  static bool read(
    const std::string& filename, std::size_t& width, std::size_t& height,
    std::vector<unsigned char>& data
  );
};

}