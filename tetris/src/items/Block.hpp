#pragma once
#include <SFML/Graphics.hpp>

class Block
{
public:
	Block(sf::Vector2i position = sf::Vector2i(0, 0), sf::Color color = sf::Color::Black);
	virtual ~Block();

	void setColor(sf::Color value);
	sf::Color getColor() const;

	void setPosition(sf::Vector2i position);
	sf::Vector2i getPosition() const;

private:
	sf::Vector2i m_position;
	sf::Color m_color;

	friend class BlockRenderer;
};

using BlockList = std::vector<Block>;

