#ifdef CRANE_PLATFORM_LINUX
#include "GlfwWindow.hpp"
#include "GlfwInput.hpp"

#include <iostream>

namespace Crane {

Window* Window::create(const WindowProperties& properties)
{
  return new GlfwWindow(properties);
}

bool GlfwWindow::m_GlfwInitialized = false;

GlfwWindow::GlfwWindow(const WindowProperties& properties)
  : m_Window(nullptr)
{
  init(properties);
}

GlfwWindow::~GlfwWindow()
{

}

void GlfwWindow::update()
{
  glfwSwapBuffers(m_Window);
  glfwPollEvents();
}

unsigned int GlfwWindow::getWidth() const
{
  GlfwWindowProperties* properties =
    (GlfwWindowProperties*)glfwGetWindowUserPointer(m_Window);

  return properties->width;
}

unsigned int GlfwWindow::getHeight() const
{
  GlfwWindowProperties* properties =
    (GlfwWindowProperties*)glfwGetWindowUserPointer(m_Window);

  return properties->height;
}

void GlfwWindow::setEventCallback(std::function<void(Event* e)> callback)
{
  GlfwWindowProperties* properties =
    (GlfwWindowProperties*)glfwGetWindowUserPointer(m_Window);

  properties->callback = callback;
}

void GlfwWindow::errorCallback(int error, const char* description)
{
  std::cerr << "GLFW Error #" << error << ": " << description << "\n";
}

void GlfwWindow::init(const WindowProperties& properties)
{
  m_Properties.title = properties.title;
  m_Properties.width = properties.width;
  m_Properties.height = properties.height;

  /* Init GLFW */
  if (!m_GlfwInitialized)
  {
    if (!glfwInit())
    {
      std::cerr << "Error: Could not initialize GLFW library\n";
      exit(EXIT_FAILURE);
    }

    glfwSetErrorCallback(errorCallback);
    m_GlfwInitialized = true;
  }

  /* Init window */
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);

  m_Window = glfwCreateWindow(
    m_Properties.width,
    m_Properties.height,
    m_Properties.title.c_str(),
    nullptr,
    nullptr
  );

  if (!m_Window)
  {
    std::cerr << "Error: Could not create window\n";
    exit(EXIT_FAILURE);
  }

  glfwMakeContextCurrent(m_Window);
  gladLoadGL();
  glfwSwapInterval(1);

  int buffer_width, buffer_height;
  glfwGetFramebufferSize(m_Window, &buffer_width, &buffer_height);
  glViewport(0, 0, buffer_width, buffer_height);

  glfwSetWindowUserPointer(m_Window, &m_Properties);

  /* Event callbacks */
  glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int w, int h)
  {
    GlfwWindowProperties* properties =
      (GlfwWindowProperties*)glfwGetWindowUserPointer(window);

    properties->callback(new WindowResizedEvent(w, h));
  });

  glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
  {
    GlfwWindowProperties* properties =
      (GlfwWindowProperties*)glfwGetWindowUserPointer(window);

    properties->callback(new WindowClosedEvent());
  });

  glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int k, int code, int action, int mods)
  {
    GlfwWindowProperties* properties =
      (GlfwWindowProperties*)glfwGetWindowUserPointer(window);
      
    if (action == GLFW_PRESS)
    {
      properties->callback(new KeyPressedEvent(GlfwToCrane(k), false));
    }
    else if (action == GLFW_REPEAT)
    {
      properties->callback(new KeyPressedEvent(GlfwToCrane(k), true));
    }
  });
}

void GlfwWindow::fini()
{
  if (m_Window != nullptr)
  {
    glfwDestroyWindow(m_Window);
    m_Window = nullptr;
  }
}

}

#endif // CRANE_PLATFORM_LINUX