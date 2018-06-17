#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "scene/game.h"

// https://en.wikipedia.org/wiki/Tetris

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 400), "Tetris");

	Game game;
	game.run(window);

	return 0;
}