#pragma once

namespace Crane {

class Application {
public:
  virtual ~Application();

  void run();

protected:
  virtual void onEvent() = 0;
  virtual void onUpdate() = 0;
  virtual void onRender() = 0;
};

}