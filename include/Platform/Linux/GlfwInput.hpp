#ifdef CRANE_PLATFORM_LINUX
#pragma once

namespace Crane {

int CraneToGlfw(Keyboard::Key k);
Keyboard::Key GlfwToCrane(int k);

}

#endif // CRANE_PLATFORM_LINUX