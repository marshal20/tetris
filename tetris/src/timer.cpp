#include "timer.hpp"

Timer::Timer(float interval) :
	m_interval(interval)
{
}

Timer::~Timer()
{
}

Timer::operator bool()
{
	if (m_clock.getElapsedTime().asSeconds() > m_interval)
	{
		m_clock.restart();
		return true;
	}

	return false;
}

float Timer::getInterval() const
{
	return m_interval;
}

void Timer::setInterval(float val)
{
	m_interval = val;
}
