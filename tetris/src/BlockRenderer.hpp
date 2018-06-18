#pragma once
#include "items/Block.hpp"
#include "items/tetris.hpp"
#include "grid.hpp"
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
	
	int getCellWidth() const;
	void setCellWidth(int val);

	sf::Color getBackgroundColor() const;
	void setBackgroundColor(sf::Color val);

	sf::Color getBoarderColor() const;
	void setBoarderColor(sf::Color val);

	int getBoarderThickness() const;
	void setBoarderThickness(int val);

private:
	BlockList m_blockList;
	int m_cellWidth = 20;
	sf::Color m_backgroundColor = sf::Color(50, 50, 50);
	sf::Color m_boarderColor = sf::Color(200, 200, 200);
	int m_boarderThickness = 1;

};

