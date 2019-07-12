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