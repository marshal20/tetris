#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "scene/game.hpp"
#include <memory>

// https://en.wikipedia.org/wiki/Tetris

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 400), "Tetris");

	std::shared_ptr<Scene> currentScene;

	// create the start scene
	currentScene = std::make_shared<Game>();

	while (currentScene)
	{
		currentScene = currentScene->run(window);
	}

	return 0;
}