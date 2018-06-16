#include "BlockRenderer.h"



BlockRenderer::BlockRenderer()
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

void BlockRenderer::submit(const grid & gr)
{
}

void BlockRenderer::end()
{

}

void BlockRenderer::render(sf::RenderWindow& target_window)
{
	for (int x = 0; x < m_gridSize.x; x++)
	{
		for (int y = 0; y < m_gridSize.y; y++)
		{
			sf::RectangleShape rec({ (float)m_cellWidth , (float)m_cellWidth });
			rec.setPosition(x * m_cellWidth, y * m_cellWidth);
			rec.setFillColor(sf::Color::Black);
			rec.setOutlineColor(sf::Color::White);
			rec.setOutlineThickness(1);

			target_window.draw(rec);
		}
	}

	for (Block b : m_blockList)
	{
		sf::RectangleShape rec({ (float)m_cellWidth , (float)m_cellWidth });
		rec.setPosition(b.m_position.x * m_cellWidth, b.m_position.y * m_cellWidth);
		rec.setFillColor(b.m_color);
		rec.setOutlineColor(sf::Color::White);
		rec.setOutlineThickness(1);

		target_window.draw(rec);
	}
}
