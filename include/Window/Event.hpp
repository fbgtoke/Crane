#pragma once

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

}