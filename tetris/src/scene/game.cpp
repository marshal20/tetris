#include "game.hpp"

Game::Game()
{
	m_tet.reset(10);

	m_gr.setGridSize({ 10, 20 });

	m_renderer.setCellWidth(20);
}

Game::~Game()
{

}

void Game::input(sf::Event event)
{
	if (event.type == sf::Event::KeyPressed)
		switch (event.key.code)
		{
		case sf::Keyboard::Right:
			m_tet.right();
			if (m_gr.checkCollision(m_tet))
				m_tet.left();
			break;

		case sf::Keyboard::Left:
			m_tet.left();
			if (m_gr.checkCollision(m_tet))
				m_tet.right();
			break;
		}
}

void Game::update(float time, float deltaTime)
{
	sf::sleep(sf::milliseconds(100));

	m_renderer.start();

	static int counter = 0;

	if (counter > 2)
	{
		m_tet.up();

		if (m_gr.checkCollision(m_tet))
		{
			m_tet.down();
			m_gr.add(m_tet);
			m_tet.reset(10);

			if (m_gr.checkCollision(m_tet))
			{
				// game over
				m_gr.reset();
			}
		}
		else
		{
			m_renderer.submit(m_tet);
		}
		counter = 0;
	}
	else
	{
		m_renderer.submit(m_tet);
	}

	counter++;
	m_gr.update();
	m_renderer.end();
}

void Game::render(sf::RenderWindow& window)
{
	window.clear();
	m_renderer.render(window, m_gr);
}

