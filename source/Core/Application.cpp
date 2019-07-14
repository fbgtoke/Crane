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

#include "Application.hpp"

#include <cassert>
#include <iostream>

/* Placeholder */
#include <GL/gl.h>

namespace Crane {

Application* Application::m_Instance = nullptr;

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

Application* Application::get()
{
  if (Application::m_Instance == nullptr)
    Application::m_Instance = createApplication();

  return Application::m_Instance;
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
  for (Layer* layer : m_LayerStack)
  {
    if (layer->onEvent(e))
    {
      break;
    }
  }
}

void Application::onUpdate()
{
  assert(m_Window != nullptr);
  m_Window->update();

  Time deltatime = Time::getGlobalTime() - m_LastFrame;
  m_LastFrame = Time::getGlobalTime();

  for (Layer* layer : m_LayerStack)
  {
    layer->onUpdate(deltatime);
  }
}

void Application::onRender()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glClear(GL_DEPTH_BUFFER_BIT);

  for (auto it = m_LayerStack.rbegin(); it != m_LayerStack.rend(); ++it)
  {
    (*it)->onRender();
  }
}

}