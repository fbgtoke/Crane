#ifdef CRANE_PLATFORM_LINUX
#include "GlfwWindow.hpp"

namespace Crane {

Window* Window::create(const WindowProperties& properties)
{
  return new GlfwWindow(properties);
}

bool GlfwWindow::m_GlfwInitialized = false;

GlfwWindow::GlfwWindow(const WindowProperties& properties)
  : m_Window(nullptr)
{
  init();
}

GlfwWindow::~GlfwWindow()
{

}

void GlfwWindow::onUpdate()
{

}

unsigned int GlfwWindow::getWidth() const
{
  GlfwWindowProperties* properties = glfwGetWindowUserPointer(m_Window);
  return properties->width;
}

unsigned int GlfwWindow::getHeight() const
{
  GlfwWindowProperties* properties = glfwGetWindowUserPointer(m_Window);
  return properties->height;
}

void GlfwWindow::errorCallback(int error, const char* description)
{
  std::cerr << "GLFW Error #" << error << ": " << description << "\n";
}

void GlfwWindow::init()
{
  m_Properties.title = properties.title;
  m_Properties.width = properties.width;
  m_Properties.height = properties.height;

  if (!m_GlfwInitialized)
  {
    if (!glfwInit())
    {
      std::cerr << "Error: Could not initialize GLFW library\n";
      exit(EXIT_FAILURE);
    }

    glfwSetErrorCallback(errorCallback);

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

    glfwMakeContextCurrent(window);

    glfwSetWindowUserPointer(m_Window, &m_Properties);
  }
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