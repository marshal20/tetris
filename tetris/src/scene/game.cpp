#include "game.hpp"

Game::Game()
{
	m_tet.reset(10);

	m_gr.setGridSize({ 10, 20 });

	m_renderer.setCellWidth(20);

	m_tetrisTimer.setInterval(1.0f / 1.0f); // interval = 1 / speed
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

		case sf::Keyboard::Up:
			m_tet.rotate(tetris::RotationDirection::ClockWise);
			if (m_gr.checkCollision(m_tet))
				m_tet.rotate(tetris::RotationDirection::CounterClockWise);
			break;

		case sf::Keyboard::Down:
			m_tet.down();
			if (m_gr.checkCollision(m_tet))
				m_tet.up();
			break;

		case sf::Keyboard::P:
			setNextScene(std::make_shared<Game>());
			break;
		}
}

void Game::update(float time, float deltaTime)
{
	sf::sleep(sf::milliseconds(100));

	if (m_tetrisTimer)
	{
		m_tet.down();

		if (m_gr.checkCollision(m_tet))
		{
			m_tet.up();
			m_gr.add(m_tet);
			m_tet.reset(10);

			if (m_gr.checkCollision(m_tet))
			{
				// game over
				m_gr.reset();
			}
		}
	}
	
	m_gr.update();
	
}

void Game::render(sf::RenderWindow& window)
{
	m_renderer.start();
	m_renderer.submit(m_tet);
	m_renderer.end();

	window.clear();
	m_renderer.render(window, m_gr);
}

