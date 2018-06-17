#pragma once
#include <vector>
#include "Block.h"

class tetris
{
public:
	tetris();
	virtual ~tetris();

	void reset(int width);

	void left();
	void right();
	void up();
	void down();

	void setColor(sf::Color value);
	sf::Color getColor() const;

	void setPosition(sf::Vector2i position);
	sf::Vector2i getPosition() const;

	void loadFromPattern(const std::string& pattern, sf::Color color);
	
	BlockList getBlocks() const;

protected:
	BlockList m_blockList;
	sf::Vector2i m_position = {0, 0};
	sf::Color m_color = sf::Color::Blue;

	friend class BlockRenderer;
};

