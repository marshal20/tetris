#include "scene.h"

Scene::Scene()
{
	m_prevTime = m_clock.getElapsedTime();
}

Scene::~Scene()
{
}

std::shared_ptr<Scene> Scene::run(sf::RenderWindow & window)
{
	m_nextScene = 0;

	sf::Time cur = m_clock.getElapsedTime();
	sf::Time delta = cur - m_prevTime;
	m_prevTime = cur;
	
	while (window.isOpen() && !m_nextScene)
	{
		update(cur.asSeconds(), delta.asSeconds());

		window.clear();
		render(window);
		window.display();

	}

	return m_nextScene;
}
