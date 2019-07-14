#pragma once

#include "Event.hpp"

#include <functional>
#include <string>

#define BIND_EVENT_CALLBACK(x) \
  std::bind(&x, this, std::placeholders::_1)

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

  virtual void update() = 0;

  virtual unsigned int getWidth() const = 0;
  virtual unsigned int getHeight() const = 0;
  virtual void setEventCallback(std::function<void(Event* e)> callback) = 0;

  static Window* create(const WindowProperties& properties);
  virtual void* getNativeWindow() = 0;
};

}