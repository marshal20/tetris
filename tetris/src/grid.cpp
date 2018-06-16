#include "grid.h"



grid::grid()
{
}


grid::~grid()
{
}

void grid::update()
{

}

bool grid::checkCollision(Block block)
{
	for (Block b : m_blockList)
	{
		if (b.getPosition() == block.getPosition())
			return true;
	}

	return false;
}

bool grid::checkCollision(tetris tet)
{
	for (Block b : tet.m_blockList)
	{
		if (checkCollision(b))
			return true;
	}

	return false;
}
