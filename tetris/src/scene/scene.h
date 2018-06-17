#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <memory>

class Scene
{
public:
	Scene();
	virtual ~Scene();

	std::shared_ptr<Scene> run(sf::RenderWindow& window);
	
protected:
	virtual void input(sf::Event event) = 0;
	virtual void update(float time, float deltaTime) = 0;
	virtual void render(sf::RenderWindow& window) = 0;

protected:
	std::shared_ptr<Scene> m_nextScene;

private:
	sf::Clock m_clock;
	sf::Time m_cur;
};