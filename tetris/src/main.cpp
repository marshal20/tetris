#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "BlockRenderer.h"
#include "items/tetris.h"
#include "items/Objects.h"

int main()
{
	tetris tet;
	tet.loadFromPattern(Pattern::Z, sf::Color::Blue);

	sf::RenderWindow window(sf::VideoMode(200, 400), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	
	grid gr;
	gr.setGridSize({ 10, 20 });

	BlockRenderer renderer;
	renderer.setCellWidth(20);

	while (window.isOpen())
	{
		sf::sleep(sf::milliseconds(250));

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
				switch (event.key.code)
				{
				case sf::Keyboard::Right:
					tet.setPosition(tet.getPosition() + sf::Vector2<int>(1, 0));
					break;

				case sf::Keyboard::Left:
					tet.setPosition(tet.getPosition() + sf::Vector2<int>(-1, 0));
					break;

				}

			
		}
		
		renderer.start();

		tet.setPosition(tet.getPosition() + sf::Vector2<int>(0, 1));

		if (gr.checkCollision(tet))
		{
			tet.setPosition(tet.getPosition() + sf::Vector2<int>(0, -1));
			gr.add(tet);
			tet.setPosition({ 0, 0 });
			tet.loadFromPattern(Pattern::L, sf::Color::Green);
		}
		else
		{
			renderer.submit(tet);
		}

		gr.update();

		renderer.end();

		window.clear();
		renderer.render(window, gr);
		window.display();
	}

	return 0;
}