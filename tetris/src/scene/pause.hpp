#pragma once
#include "scene.hpp"
#include "game.hpp"
#include <memory>
#include <SFML\Graphics.hpp>


class Pause : public Scene
{
public:
	Pause();
	~Pause();

protected:
	virtual void input(sf::Event event) override;
	virtual void update(float time, float deltaTime) override;
	virtual void render(sf::RenderWindow& window) override;

private:
	std::shared_ptr<Game> m_callerGame;
	sf::Font m_font;
};