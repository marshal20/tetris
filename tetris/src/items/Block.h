#pragma once
#include <SFML/Graphics.hpp>

class Block
{
public:
	Block(sf::Vector2<int> position, sf::Color color) :
		m_position(position), m_color(color)
	{}
	Block();
	virtual ~Block();

	void setPosition(sf::Vector2<int> position);
	sf::Vector2<int> getPosition() const;

	void setColor(sf::Color value);
	sf::Color getColor() const;

private:
	sf::Vector2<int> m_position;
	sf::Color m_color;

	friend class BlockRenderer;
	friend class tetris;
};

