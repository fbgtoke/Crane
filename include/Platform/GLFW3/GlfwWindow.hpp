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

#ifdef CRANE_PLATFORM_LINUX
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Window/Window.hpp"

namespace Crane {

class GlfwWindow : public Crane::Window {
public:
  GlfwWindow(const WindowProperties& properties);
  ~GlfwWindow() override;

  void update() override;

  unsigned int getWidth() const override;
  unsigned int getHeight() const override;
  void setEventCallback(std::function<void(Event* e)> callback) override;

  static bool initGlfw();
  static void errorCallback(int error, const char* description);

  void* getNativeWindow() override { return (void*)m_Window; }

private:
  static bool m_GlfwInitialized;

  struct GlfwWindowProperties {
    std::string title;
    unsigned int width;
    unsigned int height;

    std::function<void(Event* e)> callback;
    // more...
  };

  GlfwWindowProperties m_Properties;
  GLFWwindow* m_Window;

  void init(const WindowProperties& properties);
  void fini();
};

}

#endif // CRANE_PLATFORM_LINUX