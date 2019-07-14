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

#include "Time.hpp"

namespace Crane {

Time& Time::operator=(Time t)
{
  m_Seconds = t.m_Seconds;
  return *this;
}

bool Time::operator==(Time t) const
{
  return m_Seconds == t.m_Seconds;
}

bool Time::operator>(Time t) const
{
  return m_Seconds > t.m_Seconds;
}

Time operator+(Time t1, Time t2)
{
  return Time(t1.m_Seconds + t2.m_Seconds);
}

Time operator-(Time t1, Time t2)
{
  return Time(t1.m_Seconds - t2.m_Seconds);
}

Time& Time::operator+=(Time t)
{
  m_Seconds += t.m_Seconds;
  return *this;
}

Time& Time::operator-=(Time t)
{
  m_Seconds -= t.m_Seconds;
  return *this;
}

}