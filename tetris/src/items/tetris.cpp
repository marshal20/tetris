#include "tetris.h"



tetris::tetris()
{
}


tetris::~tetris()
{
}

void tetris::setColor(sf::Color value)
{
	m_color = value;

	for (int i = 0; i < m_blockList.size(); i++)
	{
		m_blockList[i].m_color = value;
	}
}

sf::Color tetris::getColor() const
{
	return m_color;
}

void tetris::setPosition(sf::Vector2<int> position)
{
	sf::Vector2<int> offset = position - m_position;

	m_position += offset;

	for (int i = 0; i < m_blockList.size(); i++)
	{
		m_blockList[i].m_position += offset;
	}
}

sf::Vector2<int> tetris::getPosition() const
{
	return m_position;
}
