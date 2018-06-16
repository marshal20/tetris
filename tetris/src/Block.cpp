#include "Block.h"



Block::Block()
{
}


Block::~Block()
{
}

void Block::setPosition(sf::Vector2<int> position)
{
	m_position = position;
}

sf::Vector2<int> Block::getPosition() const
{
	return m_position;
}

void Block::setColor(sf::Color value)
{
	m_color = value;
}

sf::Color Block::getColor() const
{
	return m_color;
}
