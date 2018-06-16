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

	sf::Vector2<int> getGridSize() const { return m_gridSize; }
	void setGridSize(sf::Vector2<int> val) { m_gridSize = val; }

private:
	std::vector<Block> m_blockList;
	sf::Vector2<int> m_gridSize;

	friend class BlockRenderer;
};

