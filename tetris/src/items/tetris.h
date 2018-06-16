#pragma once
#include <vector>
#include "Block.h"

class tetris
{
public:
	tetris();
	virtual ~tetris();

	void setColor(sf::Color value);
	sf::Color getColor() const;

	void setPosition(sf::Vector2<int> position);
	sf::Vector2<int> getPosition() const;

	void loadFromPattern(std::string pattern, sf::Color color);
	
	std::vector<Block> getBlocks() const;

protected:
	std::vector<Block> m_blockList;
	sf::Vector2<int> m_position = {0, 0};
	sf::Color m_color = sf::Color::Blue;

	friend class BlockRenderer;
	friend class grid;
};

