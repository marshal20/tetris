#pragma once
#include "items/Block.h"
#include "items/tetris.h"

class grid
{
public:
	grid();
	~grid();

	void update();
	bool checkCollision(Block block);
	bool checkCollision(tetris tet);
	
private:
	std::vector<Block> m_blockList;

	friend class BlockRenderer;
};

