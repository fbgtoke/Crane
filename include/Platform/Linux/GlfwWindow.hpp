#ifdef CRANE_PLATFORM_LINUX
#pragma once

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "Window/Window.hpp"

namespace Crane {

class GlfwWindow : public Window {
public:
  GlfwWindow(const WindowProperties& properties);
  ~GlfwWindow() override;

  void onUpdate() override;

  unsigned int getWidth() const override;
  unsigned int getHeight() const override;

  static void errorCallback(int error, const char* description);

private:
  static bool m_GlfwInitialized;

  struct GlfwWindowProperties {
    std::string title;
    unsigned int width;
    unsigned int height;

    // more...
  };

  GlfwWindowProperties m_Properties;
  GLFWwindow* m_Window;

  void init();
  void fini();
};

};

#endif // CRANE_PLATFORM_LINUX