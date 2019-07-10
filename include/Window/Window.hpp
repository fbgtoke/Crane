#pragma once

#include <string>

namespace Crane {

struct WindowProperties {
  std::string title;
  unsigned int width;
  unsigned int height;

  WindowProperties(const std::string& t, unsigned int w, unsigned int h);
};

class Window {
public:
  virtual ~Window() = default;

  virtual void onUpdate() = 0;

  virtual unsigned int getWidht() const = 0;
  virtual unsigned int getHeight() const = 0;

  static Window* create(const WindowProperties& properties);
};

}