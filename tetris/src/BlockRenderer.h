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

	sf::Color getBackgroundColor() const { return m_backgroundColor; }
	void setBackgroundColor(sf::Color val) { m_backgroundColor = val; }

	sf::Color getBoarderColor() const { return m_boarderColor; }
	void setBoarderColor(sf::Color val) { m_boarderColor = val; }

	int getBoarderThickness() const { return m_boarderThickness; }
	void setBoarderThickness(int val) { m_boarderThickness = val; }

private:
	BlockList m_blockList;
	int m_cellWidth = 20;
	sf::Color m_backgroundColor = sf::Color(50, 50, 50);
	sf::Color m_boarderColor = sf::Color(200, 200, 200);
	int m_boarderThickness = 1;

};

