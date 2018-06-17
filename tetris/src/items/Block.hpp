#pragma once
#include <SFML/Graphics.hpp>

class Block
{
public:
	Block(sf::Vector2i position = sf::Vector2i(0, 0), sf::Color color = sf::Color::Black);
	virtual ~Block();

	void setColor(sf::Color value) { m_color = value; }
	sf::Color getColor() const { return m_color; }

	void setPosition(sf::Vector2i position) { m_position = position; }
	sf::Vector2i getPosition() const { return m_position; }

private:
	sf::Vector2i m_position;
	sf::Color m_color;

	friend class BlockRenderer;
};

using BlockList = std::vector<Block>;

