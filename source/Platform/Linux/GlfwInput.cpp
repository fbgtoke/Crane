#ifdef CRANE_PLATFORM_LINUX
#include "Window/Input.hpp"

#include "GlfwWindow.hpp"
#include "Core/Application.hpp"

#include <GLFW/glfw3.h>

namespace Crane {

int CraneToGlfw(Keyboard::Key k)
{
  switch (k)
  {
    case Keyboard::Space:        return GLFW_KEY_SPACE;
    case Keyboard::Apostrophe:   return GLFW_KEY_APOSTROPHE;
    case Keyboard::Comma:        return GLFW_KEY_COMMA;
    case Keyboard::Minus:        return GLFW_KEY_MINUS;
    case Keyboard::Period:       return GLFW_KEY_PERIOD;
    case Keyboard::Slash:        return GLFW_KEY_SLASH;
    case Keyboard::Num0:         return GLFW_KEY_0;
    case Keyboard::Num1:         return GLFW_KEY_1;
    case Keyboard::Num2:         return GLFW_KEY_2;
    case Keyboard::Num3:         return GLFW_KEY_3;
    case Keyboard::Num4:         return GLFW_KEY_4;
    case Keyboard::Num5:         return GLFW_KEY_5;
    case Keyboard::Num6:         return GLFW_KEY_6;
    case Keyboard::Num7:         return GLFW_KEY_7;
    case Keyboard::Num8:         return GLFW_KEY_8;
    case Keyboard::Num9:         return GLFW_KEY_9;
    case Keyboard::Semicolon:    return GLFW_KEY_SEMICOLON;
    case Keyboard::Equal:        return GLFW_KEY_EQUAL;
    case Keyboard::A:            return GLFW_KEY_A;
    case Keyboard::B:            return GLFW_KEY_B;
    case Keyboard::C:            return GLFW_KEY_C;
    case Keyboard::D:            return GLFW_KEY_D;
    case Keyboard::E:            return GLFW_KEY_E;
    case Keyboard::F:            return GLFW_KEY_F;
    case Keyboard::G:            return GLFW_KEY_G;
    case Keyboard::H:            return GLFW_KEY_H;
    case Keyboard::I:            return GLFW_KEY_I;
    case Keyboard::J:            return GLFW_KEY_J;
    case Keyboard::K:            return GLFW_KEY_K;
    case Keyboard::L:            return GLFW_KEY_L;
    case Keyboard::M:            return GLFW_KEY_M;
    case Keyboard::N:            return GLFW_KEY_N;
    case Keyboard::O:            return GLFW_KEY_O;
    case Keyboard::P:            return GLFW_KEY_P;
    case Keyboard::Q:            return GLFW_KEY_Q;
    case Keyboard::R:            return GLFW_KEY_R;
    case Keyboard::S:            return GLFW_KEY_S;
    case Keyboard::T:            return GLFW_KEY_T;
    case Keyboard::U:            return GLFW_KEY_U;
    case Keyboard::V:            return GLFW_KEY_V;
    case Keyboard::W:            return GLFW_KEY_W;
    case Keyboard::X:            return GLFW_KEY_X;
    case Keyboard::Y:            return GLFW_KEY_Y;
    case Keyboard::Z:            return GLFW_KEY_Z;
    case Keyboard::LeftBracket:  return GLFW_KEY_LEFT_BRACKET;
    case Keyboard::Backslash:    return GLFW_KEY_BACKSLASH;
    case Keyboard::RightBracket: return GLFW_KEY_RIGHT_BRACKET;
    case Keyboard::GraveAccent:  return GLFW_KEY_GRAVE_ACCENT;
    case Keyboard::Escape:       return GLFW_KEY_ESCAPE;
    case Keyboard::Enter:        return GLFW_KEY_ENTER;
    case Keyboard::Tab:          return GLFW_KEY_TAB;
    case Keyboard::Backspace:    return GLFW_KEY_BACKSPACE;
    case Keyboard::Insert:       return GLFW_KEY_INSERT;
    case Keyboard::Delete:       return GLFW_KEY_DELETE;
    case Keyboard::Right:        return GLFW_KEY_RIGHT;
    case Keyboard::Left:         return GLFW_KEY_LEFT;
    case Keyboard::Down:         return GLFW_KEY_DOWN;
    case Keyboard::Up:           return GLFW_KEY_UP;
    case Keyboard::PageUp:       return GLFW_KEY_PAGE_UP;
    case Keyboard::PageDown:     return GLFW_KEY_PAGE_DOWN;
    case Keyboard::Home:         return GLFW_KEY_HOME;
    case Keyboard::End:          return GLFW_KEY_END;
    case Keyboard::CapsLock:     return GLFW_KEY_CAPS_LOCK;
    case Keyboard::ScrollLock:   return GLFW_KEY_SCROLL_LOCK;
    case Keyboard::NumLock:      return GLFW_KEY_NUM_LOCK;
    case Keyboard::PrintScreen:  return GLFW_KEY_PRINT_SCREEN;
    case Keyboard::Pause:        return GLFW_KEY_PAUSE;
    case Keyboard::F1:           return GLFW_KEY_F1;
    case Keyboard::F2:           return GLFW_KEY_F2;
    case Keyboard::F3:           return GLFW_KEY_F3;
    case Keyboard::F4:           return GLFW_KEY_F4;
    case Keyboard::F5:           return GLFW_KEY_F5;
    case Keyboard::F6:           return GLFW_KEY_F6;
    case Keyboard::F7:           return GLFW_KEY_F7;
    case Keyboard::F8:           return GLFW_KEY_F8;
    case Keyboard::F9:           return GLFW_KEY_F9;
    case Keyboard::F10:          return GLFW_KEY_F10;
    case Keyboard::F11:          return GLFW_KEY_F11;
    case Keyboard::F12:          return GLFW_KEY_F12;
    case Keyboard::F13:          return GLFW_KEY_F13;
    case Keyboard::F14:          return GLFW_KEY_F14;
    case Keyboard::F15:          return GLFW_KEY_F15;
    case Keyboard::F16:          return GLFW_KEY_F16;
    case Keyboard::F17:          return GLFW_KEY_F17;
    case Keyboard::F18:          return GLFW_KEY_F18;
    case Keyboard::F19:          return GLFW_KEY_F19;
    case Keyboard::F20:          return GLFW_KEY_F20;
    case Keyboard::F21:          return GLFW_KEY_F21;
    case Keyboard::F22:          return GLFW_KEY_F22;
    case Keyboard::F23:          return GLFW_KEY_F23;
    case Keyboard::F24:          return GLFW_KEY_F24;
    case Keyboard::F25:          return GLFW_KEY_F25;
    case Keyboard::LeftShift:    return GLFW_KEY_LEFT_SHIFT;
    case Keyboard::LeftControl:  return GLFW_KEY_LEFT_CONTROL;
    case Keyboard::LeftAlt:      return GLFW_KEY_LEFT_ALT;
    case Keyboard::LeftSuper:    return GLFW_KEY_LEFT_SUPER;
    case Keyboard::RightShift:   return GLFW_KEY_RIGHT_SHIFT;
    case Keyboard::RightControl: return GLFW_KEY_RIGHT_CONTROL;
    case Keyboard::RightAlt:     return GLFW_KEY_RIGHT_ALT;
    case Keyboard::RightSuper:   return GLFW_KEY_RIGHT_SUPER;
    case Keyboard::Menu:         return GLFW_KEY_MENU;

    default: return GLFW_KEY_UNKNOWN;
  }
}

Keyboard::Key GlfwToCrane(int k)
{
  switch (k)
  {
    case GLFW_KEY_SPACE:         return Keyboard::Space;
    case GLFW_KEY_APOSTROPHE:    return Keyboard::Apostrophe;
    case GLFW_KEY_COMMA:         return Keyboard::Comma;
    case GLFW_KEY_MINUS:         return Keyboard::Minus;
    case GLFW_KEY_PERIOD:        return Keyboard::Period;
    case GLFW_KEY_SLASH:         return Keyboard::Slash;
    case GLFW_KEY_0:             return Keyboard::Num0;
    case GLFW_KEY_1:             return Keyboard::Num1;
    case GLFW_KEY_2:             return Keyboard::Num2;
    case GLFW_KEY_3:             return Keyboard::Num3;
    case GLFW_KEY_4:             return Keyboard::Num4;
    case GLFW_KEY_5:             return Keyboard::Num5;
    case GLFW_KEY_6:             return Keyboard::Num6;
    case GLFW_KEY_7:             return Keyboard::Num7;
    case GLFW_KEY_8:             return Keyboard::Num8;
    case GLFW_KEY_9:             return Keyboard::Num9;
    case GLFW_KEY_SEMICOLON:     return Keyboard::Semicolon;
    case GLFW_KEY_EQUAL:         return Keyboard::Equal;
    case GLFW_KEY_A:             return Keyboard::A;
    case GLFW_KEY_B:             return Keyboard::B;
    case GLFW_KEY_C:             return Keyboard::C;
    case GLFW_KEY_D:             return Keyboard::D;
    case GLFW_KEY_E:             return Keyboard::E;
    case GLFW_KEY_F:             return Keyboard::F;
    case GLFW_KEY_G:             return Keyboard::G;
    case GLFW_KEY_H:             return Keyboard::H;
    case GLFW_KEY_I:             return Keyboard::I;
    case GLFW_KEY_J:             return Keyboard::J;
    case GLFW_KEY_K:             return Keyboard::K;
    case GLFW_KEY_L:             return Keyboard::L;
    case GLFW_KEY_M:             return Keyboard::M;
    case GLFW_KEY_N:             return Keyboard::N;
    case GLFW_KEY_O:             return Keyboard::O;
    case GLFW_KEY_P:             return Keyboard::P;
    case GLFW_KEY_Q:             return Keyboard::Q;
    case GLFW_KEY_R:             return Keyboard::R;
    case GLFW_KEY_S:             return Keyboard::S;
    case GLFW_KEY_T:             return Keyboard::T;
    case GLFW_KEY_U:             return Keyboard::U;
    case GLFW_KEY_V:             return Keyboard::V;
    case GLFW_KEY_W:             return Keyboard::W;
    case GLFW_KEY_X:             return Keyboard::X;
    case GLFW_KEY_Y:             return Keyboard::Y;
    case GLFW_KEY_Z:             return Keyboard::Z;
    case GLFW_KEY_LEFT_BRACKET:  return Keyboard::LeftBracket;
    case GLFW_KEY_BACKSLASH:     return Keyboard::Backslash;
    case GLFW_KEY_RIGHT_BRACKET: return Keyboard::RightBracket;
    case GLFW_KEY_GRAVE_ACCENT:  return Keyboard::GraveAccent;
    case GLFW_KEY_ESCAPE:        return Keyboard::Escape;
    case GLFW_KEY_ENTER:         return Keyboard::Enter;
    case GLFW_KEY_TAB:           return Keyboard::Tab;
    case GLFW_KEY_BACKSPACE:     return Keyboard::Backspace;
    case GLFW_KEY_INSERT:        return Keyboard::Insert;
    case GLFW_KEY_DELETE:        return Keyboard::Delete;
    case GLFW_KEY_RIGHT:         return Keyboard::Right;
    case GLFW_KEY_LEFT:          return Keyboard::Left;
    case GLFW_KEY_DOWN:          return Keyboard::Down;
    case GLFW_KEY_UP:            return Keyboard::Up;
    case GLFW_KEY_PAGE_UP:       return Keyboard::PageUp;
    case GLFW_KEY_PAGE_DOWN:     return Keyboard::PageDown;
    case GLFW_KEY_HOME:          return Keyboard::Home;
    case GLFW_KEY_END:           return Keyboard::End;
    case GLFW_KEY_CAPS_LOCK:     return Keyboard::CapsLock;
    case GLFW_KEY_SCROLL_LOCK:   return Keyboard::ScrollLock;
    case GLFW_KEY_NUM_LOCK:      return Keyboard::NumLock;
    case GLFW_KEY_PRINT_SCREEN:  return Keyboard::PrintScreen;
    case GLFW_KEY_PAUSE:         return Keyboard::Pause;
    case GLFW_KEY_F1:            return Keyboard::F1;
    case GLFW_KEY_F2:            return Keyboard::F2;
    case GLFW_KEY_F3:            return Keyboard::F3;
    case GLFW_KEY_F4:            return Keyboard::F4;
    case GLFW_KEY_F5:            return Keyboard::F5;
    case GLFW_KEY_F6:            return Keyboard::F6;
    case GLFW_KEY_F7:            return Keyboard::F7;
    case GLFW_KEY_F8:            return Keyboard::F8;
    case GLFW_KEY_F9:            return Keyboard::F9;
    case GLFW_KEY_F10:           return Keyboard::F10;
    case GLFW_KEY_F11:           return Keyboard::F11;
    case GLFW_KEY_F12:           return Keyboard::F12;
    case GLFW_KEY_F13:           return Keyboard::F13;
    case GLFW_KEY_F14:           return Keyboard::F14;
    case GLFW_KEY_F15:           return Keyboard::F15;
    case GLFW_KEY_F16:           return Keyboard::F16;
    case GLFW_KEY_F17:           return Keyboard::F17;
    case GLFW_KEY_F18:           return Keyboard::F18;
    case GLFW_KEY_F19:           return Keyboard::F19;
    case GLFW_KEY_F20:           return Keyboard::F20;
    case GLFW_KEY_F21:           return Keyboard::F21;
    case GLFW_KEY_F22:           return Keyboard::F22;
    case GLFW_KEY_F23:           return Keyboard::F23;
    case GLFW_KEY_F24:           return Keyboard::F24;
    case GLFW_KEY_F25:           return Keyboard::F25;
    case GLFW_KEY_LEFT_SHIFT:    return Keyboard::LeftShift;
    case GLFW_KEY_LEFT_CONTROL:  return Keyboard::LeftControl;
    case GLFW_KEY_LEFT_ALT:      return Keyboard::LeftAlt;
    case GLFW_KEY_LEFT_SUPER:    return Keyboard::LeftSuper;
    case GLFW_KEY_RIGHT_SHIFT:   return Keyboard::RightShift;
    case GLFW_KEY_RIGHT_CONTROL: return Keyboard::RightControl;
    case GLFW_KEY_RIGHT_ALT:     return Keyboard::RightAlt;
    case GLFW_KEY_RIGHT_SUPER:   return Keyboard::RightSuper;
    case GLFW_KEY_MENU:          return Keyboard::Menu;
    default: return Keyboard::Unknown;
  }
}

bool Input::isKeyPressed(Keyboard::Key k)
{
  GlfwWindow* window = (GlfwWindow*) Application::get()->getWindow();
  GLFWwindow* native_window = (GLFWwindow*) window->getNativeWindow();
 
  int state = glfwGetKey(native_window, CraneToGlfw(k));

  return (state == GLFW_PRESS) || (state == GLFW_REPEAT);
}

}

#endif // CRANE_PLATFORM_LINUX