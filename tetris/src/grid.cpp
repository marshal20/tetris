#include "grid.hpp"



grid::grid()
{
}


grid::~grid()
{
}

int grid::update()
{
	int lineCleared = 0;

	for (int y = 0; y < m_gridSize.y; y++)
	{
		if (getLineBlockCount(y) == m_gridSize.x)
		{
			removeLine(y);
			lineCleared++;
		}
	}

	return lineCleared;
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

	if (block.getPosition().x >= m_gridSize.x || block.getPosition().x < 0)
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

void grid::reset()
{
	m_blockList.clear();
}

int grid::getLineBlockCount(int lineNo) const
{
	int result = 0;
	for (Block b : m_blockList)
	{
		if (b.getPosition().y == lineNo)
			result++;
	}

	return result;
}

void grid::removeLine(int lineNo)
{
	auto new_end = std::remove_if(m_blockList.begin(), m_blockList.end(), [lineNo](const Block& b) {
		return (b.getPosition().y == lineNo);
	});

	m_blockList.erase(new_end, m_blockList.end());

	for (Block& b : m_blockList)
	{
		if (b.getPosition().y < lineNo)
		{
			b.setPosition(b.getPosition() + sf::Vector2i({ 0, 1 }));
		}
	}
}
