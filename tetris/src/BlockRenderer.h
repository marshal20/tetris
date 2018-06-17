#pragma once
#include "items/Block.h"
#include "items/tetris.h"
#include "grid.h"
#include <vector>

class BlockRenderer
{
public:
	BlockRenderer();
	virtual ~BlockRenderer();

	void start();

	void submit(const Block& block);
	void submit(const tetris& tet);

	void end();

	void render(sf::RenderWindow& target_window, grid gr);
	
	int getCellWidth() const { return m_cellWidth; }
	void setCellWidth(int val) { m_cellWidth = val; }

private:
	BlockList m_blockList;
	int m_cellWidth;

};

