#pragma once
#include "items/Block.h"
#include "items/tetris.h"
#include <vector>

class BlockRenderer
{
public:
	BlockRenderer();
	virtual ~BlockRenderer();

	void start();

	void submit(const Block& block);
	void submit(const tetris& tet);
	void submit(const grid& gr);

	void end();

	void render(sf::RenderWindow& target_window);
	
	int getCellWidth() const { return m_cellWidth; }
	void setCellWidth(int val) { m_cellWidth = val; }

	sf::Vector2<int> getGridSize() const { return m_gridSize; }
	void setGridSize(sf::Vector2<int> val) { m_gridSize = val; }

private:
	std::vector<Block> m_blockList;

	sf::Vector2<int> m_gridSize;
	int m_cellWidth;

};

