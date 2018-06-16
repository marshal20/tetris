#include <SFML/Graphics.hpp>
#include "BlockRenderer.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(200, 400), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	BlockRenderer renderer;
	renderer.setGridSize({ 10, 20 });
	renderer.setCellWidth(20);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		renderer.render(window);
		window.display();
	}

	return 0;
}