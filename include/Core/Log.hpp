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

#include <iostream>
#include <string>

namespace Crane {

class Log {
public:
  Log(const std::string& name)
    : m_Name(name) {}

  inline static Log* getLogger() { return m_Logger; }

  template <typename T, typename... Args>
  void info(T t, Args... args)
  {
    print("32", t, args...);
  }

  template <typename T, typename... Args>
  void warning(T t, Args... args)
  {
    print("33", t, args...);
  }

  template <typename T, typename... Args>
  void error(T t, Args... args)
  {
    print("31", t, args...);
  }

  void flush()
  {
    std::cout << std::flush;
  }

private:
  static Log* m_Logger;

  std::string m_Name;

  template <typename T, typename... Args>
  void print(const std::string& code_color, T t, Args... args)
  {
    std::cout << "\033[1;" + code_color + "m";
    std::cout << "[" << m_Name << "] ";
    std::cout << "\033[0;" + code_color + "m";
    print_recursive(t, args...);
    std::cout << "\n" << "\033[0m";
  }

  template <typename T>
  void print_recursive(T t)
  {
    std::cout << t << " ";
  }

  template <typename T, typename... Args>
  void print_recursive(T t, Args... args)
  {
    std::cout << t << " ";
    print_recursive(args...);
  }

};

}

#ifdef DEBUG

#define CRANE_LOG_INFO(...) \
  ::Crane::Log::getLogger()->info(__VA_ARGS__)

#define CRANE_LOG_WARN(...) \
  ::Crane::Log::getLogger()->warning(__VA_ARGS__)

#define CRANE_LOG_ERROR(...) \
  ::Crane::Log::getLogger()->error(__VA_ARGS__)

#define CRANE_LOG_FATAL(...) \
  ::Crane::Log::getLogger()->error(__VA_ARGS__); \
  exit(EXIT_FAILURE)   

#else

#define CRANE_LOG_INFO(...)

#define CRANE_LOG_WARN(...)

#define CRANE_LOG_ERROR(...)

#define CRANE_LOG_FATAL(...)

#endif // DEBUG