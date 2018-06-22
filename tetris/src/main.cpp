#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "scene/game.hpp"
#include <memory>
#include <stack>

// https://en.wikipedia.org/wiki/Tetris

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 400), "Tetris");
	std::stack<std::shared_ptr<Scene>> sceneStack;

	sceneStack.push(std::make_shared<Game>());

	while (sceneStack.top())
	{
		std::shared_ptr<Scene> curScene = sceneStack.top();
		curScene->run(window);
		if (curScene->isDone())
			sceneStack.pop();
		sceneStack.push(curScene->getNextScene());
	}

	return 0;
}