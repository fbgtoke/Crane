#include "Application.hpp"

#include <cassert>
#include <iostream>

/* Placeholder */
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Crane {

Application::Application()
  : m_Running(false)
{  
  m_Window = Window::create({ "CraneSandbox", 480, 480 });
  assert(m_Window != nullptr);

  m_Window->setEventCallback(BIND_EVENT_CALLBACK(Application::onEvent));
}

Application::~Application()
{
  delete m_Window;
}

void Application::run()
{
  assert(!m_Running);
  m_Running = true;

  while (m_Running)
  {
    onUpdate();
    onRender();
  }
}

void Application::end()
{
  m_Running = false;
}

void Application::onEvent(Event* e)
{

}

void Application::onUpdate()
{
  assert(m_Window != nullptr);
  m_Window->update();
}

void Application::onRender()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_DEPTH_BUFFER_BIT);
}

}