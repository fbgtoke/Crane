#pragma once

#include "Window/Window.hpp"

namespace Crane {

class Application {
public:
  Application();
  virtual ~Application();

  void run();
  void end();

protected:
  virtual void onEvent(Event* e);
  virtual void onUpdate();
  virtual void onRender();

private:
  Window* m_Window;

  bool m_Running;
};

}