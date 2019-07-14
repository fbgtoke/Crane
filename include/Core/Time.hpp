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