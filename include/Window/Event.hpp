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

#include "Key.hpp"

namespace Crane {

class Event {
public:
  typedef enum {
    WindowClosed, WindowResized,
    KeyPressed, KeyReleased,
    MouseMove, MouseButtonPressed, MouseButtonReleased
  } EventType;

  virtual ~Event() = default;

  virtual EventType getType() const = 0;
};

/******************************************************************************/
/* Window Events                                                              */
/******************************************************************************/
class WindowClosedEvent : public Event {
public:
  EventType getType() const override { return Event::WindowClosed; }
};

class WindowResizedEvent : public Event {
public:
  WindowResizedEvent(int w, int h)
    : m_Width(w), m_Height(h) {};

  EventType getType() const override { return Event::WindowResized; }

  int getWidth() const { return m_Width; }
  int getHeight() const { return m_Height; }

private:
  int m_Width;
  int m_Height;
};

/******************************************************************************/
/* Keyboard Events                                                            */
/******************************************************************************/
class KeyPressedEvent : public Event {
public:
  KeyPressedEvent(Keyboard::Key k, bool repeat)
    : m_Key(k), m_Repeat(repeat) {}

  EventType getType() const override { return Event::KeyPressed; }

  Keyboard::Key getKey() const { return m_Key; }
  bool isRepeat() const { return m_Repeat; }

private:
  Keyboard::Key m_Key;
  bool m_Repeat;
};

}