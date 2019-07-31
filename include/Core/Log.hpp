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

#ifdef DEBUG

#include <spdlog/spdlog.h>

#include <memory>

namespace Crane {

class Log {
public:
  static void init();

  inline static std::shared_ptr<spdlog::logger> getLogger() { return m_Logger; }

private:
  static std::shared_ptr<spdlog::logger> m_Logger;
};

}

#define CRANE_LOG_TRACE(...) \
  ::Crane::Log::getLogger()->trace(__VA_ARGS__)

#define CRANE_LOG_INFO(...) \
  ::Crane::Log::getLogger()->info(__VA_ARGS__)

#define CRANE_LOG_WARN(...) \
  ::Crane::Log::getLogger()->warn(__VA_ARGS__)

#define CRANE_LOG_ERROR(...) \
  ::Crane::Log::getLogger()->error(__VA_ARGS__)

#define CRANE_LOG_FATAL(...) \
  ::Crane::Log::getLogger()->critical(__VA_ARGS__); \
  exit(EXIT_FAILURE)

#define CRANE_GL_CALL(...)                                        \
  __VA_ARGS__;                                                    \
  {                                                               \
    int _err;                                                     \
    while ((_err = glGetError()))                                 \
    {                                                             \
      CRANE_LOG_FATAL(                                            \
        "{0}:{1} OpenGL Error: 0x{2:x}", __FILE__, __LINE__, _err \
      );                                                          \
    }                                                             \
  }                                                               

#else

namespace Crane {

class Log {
public:
  static void init() {};
};

}

#define CRANE_LOG_TRACE(...)

#define CRANE_LOG_INFO(...)

#define CRANE_LOG_WARN(...)

#define CRANE_LOG_ERROR(...)

#define CRANE_LOG_FATAL(...)

#define CRANE_OPENGL_CALL(...)

#endif // DEBUG