#pragma once

#include "Window/Window.hpp"

namespace Crane {

class Application {
public:
  virtual ~Application();

  static Application* get();
  void run();
  void end();

  inline Window* getWindow() { return m_Window; }

protected:
  Application();

  static Application* m_Instance;
  static Application* createApplication();

  virtual void onEvent(Event* e);
  virtual void onUpdate();
  virtual void onRender();

private:
  Window* m_Window;

  bool m_Running;
};

}