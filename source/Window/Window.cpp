#include "Window.hpp"

namespace Crane {

WindowProperties::WindowProperties
(
  const std::string& t, unsigned int w, unsigned int h
) : title(t), width(w), height(h) {}

}