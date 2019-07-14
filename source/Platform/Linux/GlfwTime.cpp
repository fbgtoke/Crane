#ifdef CRANE_PLATFORM_LINUX

#include "Core/Time.hpp"

#include <GLFW/glfw3.h>

namespace Crane {

Time Time::getGlobalTime()
{
  return glfwGetTime();
}

}

#endif // CRANE_PLATFORM_LINUX