#include "grid.h"



grid::grid()
{
}


grid::~grid()
{
}

int grid::update()
{
	return 0;
}

bool grid::checkCollision(Block block)
{
	for (Block b : m_blockList)
	{
		if (b.getPosition() == block.getPosition())
			return true;
	}

	if (block.getPosition().y >= m_gridSize.y)
		return true;

	return false;
}

bool grid::checkCollision(tetris tet)
{
	auto blocks = tet.getBlocks();
	for (Block b : blocks)
	{
		if (checkCollision(b))
			return true;
	}

	return false;
}

void grid::add(tetris tet)
{
	auto blocks = tet.getBlocks();
	for (Block b : blocks)
	{
		m_blockList.push_back(b);
	}
}
