#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "scene/game.hpp"
#include "scene/sceneRunner.hpp"

// https://en.wikipedia.org/wiki/Tetris

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 400), "Tetris");
	SceneRunner sceneRunner(std::make_shared<Game>());

	sceneRunner.start(window);

	return 0;
}