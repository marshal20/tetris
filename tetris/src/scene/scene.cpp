#include "scene.hpp"
#include <iostream>

Scene::Scene()
{
	m_cur = sf::Time::Zero;
}

Scene::~Scene()
{
}

std::shared_ptr<Scene> Scene::run(sf::RenderWindow & window)
{
	m_nextScene = 0;
	
	while (window.isOpen() && !m_nextScene && !m_exit)
	{
		// handling time
		sf::Time delta = m_clock.restart();
		m_cur += delta;

		// handling events
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			else
				input(event);
		}

		// updating
		update(m_cur.asSeconds(), delta.asSeconds());

		// rendering
		render(window);
		window.display();

	}

	return m_nextScene;
}
