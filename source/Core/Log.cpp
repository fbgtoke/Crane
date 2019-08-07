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

#include <iostream>

namespace Crane {

Log* Log::m_Logger = new Log("CRANE");

}

/*
[0;31m  Red
[1;31m  Bold Red
[0;32m  Green
[1;32m  Bold Green
[0;33m  Yellow
[01;33m Bold Yellow
[0;34m  Blue
[1;34m  Bold Blue
[0;35m  Magenta
[1;35m  Bold Magenta
[0;36m  Cyan
[1;36m  Bold Cyan
[0m Reset
*/