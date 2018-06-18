#include "BlockRenderer.hpp"



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


void BlockRenderer::end()
{

}

void BlockRenderer::render(sf::RenderWindow& target_window, grid gr)
{
	for (int x = 0; x < gr.m_gridSize.x; x++)
	{
		for (int y = 0; y < gr.m_gridSize.y; y++)
		{
			sf::RectangleShape rec({ (float)m_cellWidth , (float)m_cellWidth });
			rec.setPosition(x * m_cellWidth, y * m_cellWidth);
			rec.setFillColor(getBackgroundColor());
			rec.setOutlineColor(getBoarderColor());
			rec.setOutlineThickness(getBoarderThickness());

			target_window.draw(rec);
		}
	}

	for (Block b : gr.m_blockList)
	{
		m_blockList.push_back(b);
	}

	for (Block b : m_blockList)
	{
		sf::RectangleShape rec({ (float)m_cellWidth , (float)m_cellWidth });
		rec.setPosition(b.m_position.x * m_cellWidth, b.m_position.y * m_cellWidth);
		rec.setFillColor(b.m_color);
		rec.setOutlineColor(getBoarderColor());
		rec.setOutlineThickness(getBoarderThickness());

		target_window.draw(rec);
	}
}

int BlockRenderer::getCellWidth() const
{
	return m_cellWidth;
}

void BlockRenderer::setCellWidth(int val)
{
	m_cellWidth = val;
}

sf::Color BlockRenderer::getBackgroundColor() const
{
	return m_backgroundColor;
}

void BlockRenderer::setBackgroundColor(sf::Color val)
{
	m_backgroundColor = val;
}

sf::Color BlockRenderer::getBoarderColor() const
{
	return m_boarderColor;
}

void BlockRenderer::setBoarderColor(sf::Color val)
{
	m_boarderColor = val;
}

int BlockRenderer::getBoarderThickness() const
{
	return m_boarderThickness;
}

void BlockRenderer::setBoarderThickness(int val)
{
	m_boarderThickness = val;
}
