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

void BlockRenderer::end()
{

}

void BlockRenderer::render(sf::RenderWindow& target_window)
{
	// TODO
}
