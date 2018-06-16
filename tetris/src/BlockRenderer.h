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

	void end();

	void render(sf::RenderWindow& target_window);
	
private:
	std::vector<Block> m_blockList;
};

