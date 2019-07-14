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