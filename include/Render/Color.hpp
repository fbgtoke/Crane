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

#include "Math/Vec4.hpp"

namespace Crane {

class Color : public Math::Vec4 {
public:
  static const Color   Red(1.f, 0.f, 0.f, 1.f);
  static const Color Green(0.f, 1.f, 0.f, 1.f);
  static const Color  Blue(0.f, 0.f, 1.f, 1.f);

  static const Color  Yellow(1.f, 1.f, 0.f, 1.f);
  static const Color    Cyan(0.f, 1.f, 1.f, 1.f);
  static const Color Magenta(1.f, 0.f, 1.f, 1.f);

  static const Color Black(0.f, 0.f, 0.f, 1.f);
  static const Color White(1.f, 1.f, 1.f, 1.f);
};

}