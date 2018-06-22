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
	std::shared_ptr<Scene> getNextScene();
	bool isDone();

protected:
	virtual void input(sf::Event event) = 0;
	virtual void update(float time, float deltaTime) = 0;
	virtual void render(sf::RenderWindow& window) = 0;

	void setNextScene(std::shared_ptr<Scene> scene);
	void exit();
	void setDone(bool value);

private:
	bool m_exit = false;
	bool m_done = true;

private:
	sf::Clock m_clock;
	sf::Time m_cur;

	std::shared_ptr<Scene> m_nextScene;
};