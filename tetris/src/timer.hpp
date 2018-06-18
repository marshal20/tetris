#pragma once
#include <SFML/System.hpp>

class Timer
{
public:
	Timer(float interval = 0.5f);
	~Timer();


	operator bool();

	float getInterval() const;
	void setInterval(float val);

private:
	sf::Clock m_clock;
	float m_interval;
};