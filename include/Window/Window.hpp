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

#include "Event.hpp"

#include <functional>
#include <string>

#define BIND_EVENT_CALLBACK(x) \
  std::bind(&x, this, std::placeholders::_1)

namespace Crane {

struct WindowProperties {
  std::string title;
  uint32_t width;
  uint32_t height;

  WindowProperties(const std::string& t, uint32_t w, uint32_t h);
};

class Window {
public:
  virtual ~Window() = default;

  virtual void update() = 0;

  virtual uint32_t getWidth() const = 0;
  virtual uint32_t getHeight() const = 0;
  virtual void setEventCallback(std::function<void(Event* e)> callback) = 0;

  static Window* create(const WindowProperties& properties);
  virtual void* getNativeWindow() = 0;
};

}