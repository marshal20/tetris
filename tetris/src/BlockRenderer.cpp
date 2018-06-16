#include "BlockRenderer.h"



BlockRenderer::BlockRenderer()
{
}


BlockRenderer::BlockRenderer()
{

}

BlockRenderer::~BlockRenderer()
{
}

BlockRenderer::~BlockRenderer()
{

}

void BlockRenderer::start()
{
	m_blockList.clear();
}

void BlockRenderer::submit(const Block& block)
{
	m_blockList.push_back(block);
}

void BlockRenderer::submit(const tetris& tet)
{
	auto blocks = tet.getBlocks();
	for (Block b : blocks)
	{
		m_blockList.push_back(b);
	}
}

void BlockRenderer::end()
{

}

void BlockRenderer::render(sf::RenderWindow& target_window)
{
	// TODO
}
