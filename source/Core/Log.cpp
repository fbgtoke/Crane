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

#include "Log.hpp"

#include <spdlog/sinks/stdout_color_sinks.h>

namespace Crane {

std::shared_ptr<spdlog::logger> Log::m_Logger;

void Log::init()
{
  spdlog::set_pattern("%^[%T] %n: %v%$");

  m_Logger = spdlog::stdout_color_mt("CRANE");
  m_Logger->set_level(spdlog::level::trace);
}

}