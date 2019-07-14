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