#pragma once
#include "scene.h"
#include "../BlockRenderer.h"
#include "../items/tetris.h"

class Game : public Scene
{
public:
	Game();
	~Game();

protected:
	virtual void input(sf::Event event) override;
	virtual void update(float time, float deltaTime) override;
	virtual void render(sf::RenderWindow& window) override;

private:
	BlockRenderer m_renderer;
	grid m_gr;
	tetris m_tet;

};