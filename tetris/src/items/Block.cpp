#include "Block.hpp"

Block::Block(sf::Vector2i position, sf::Color color) :
	m_position(position), m_color(color)
{
}

Block::~Block()
{
}

void Block::setColor(sf::Color value)
{
	m_color = value;
}

sf::Color Block::getColor() const
{
	return m_color;
}

void Block::setPosition(sf::Vector2i position)
{
	m_position = position;
}

sf::Vector2i Block::getPosition() const
{
	return m_position;
}

