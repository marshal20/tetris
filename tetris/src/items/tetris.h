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


protected:
	std::vector<Block> m_blockList;
	sf::Vector2<int> m_position;
	sf::Color m_color;

	friend class BlockRenderer;
};

