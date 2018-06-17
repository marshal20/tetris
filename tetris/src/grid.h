#pragma once
#include "items/Block.h"
#include "items/tetris.h"

class grid
{
public:
	grid();
	~grid();

	int update();
	bool checkCollision(Block block);
	bool checkCollision(tetris tet);
	
	void add(tetris tet);

	void reset();

	sf::Vector2i getGridSize() const { return m_gridSize; }
	void setGridSize(sf::Vector2i val) { m_gridSize = val; }

private:
	int getLineBlockCount(int lineNo) const;
	void removeLine(int lineNo);

private:
	BlockList m_blockList;
	sf::Vector2i m_gridSize;

	friend class BlockRenderer;
};

