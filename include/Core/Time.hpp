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

namespace Crane {

class Time {
public:
  Time() : m_Seconds(0) {}
  Time(float s) : m_Seconds(s) {}
  Time(const Time& t) : m_Seconds(t.m_Seconds) {}

  static Time getGlobalTime();

  static Time seconds(float s) { return Time(s); }
  static Time milliseconds(float m) { return Time(m/1000.f); }

  Time& operator=(Time t);

  bool operator==(Time t) const;
  bool operator>(Time t) const;

  friend Time operator+(Time t1, Time t2);
  friend Time operator-(Time t1, Time t2);

  Time& operator+=(Time t);
  Time& operator-=(Time t);

  inline float asSeconds() const { return m_Seconds; }
  inline float asMilliseconds() const { return m_Seconds * 1000.f; }

private:
  float m_Seconds;
};

}