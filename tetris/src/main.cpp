#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "BlockRenderer.h"
#include "items/tetris.h"
#include "items/Objects.h"

int main()
{
	BlockRenderer renderer;
	grid gr;
	tetris tet;

	tet.reset(10);
	if (gr.checkCollision(tet))
	{
		// game over
	}

	sf::RenderWindow window(sf::VideoMode(200, 400), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);
	
	
	gr.setGridSize({ 10, 20 });

	renderer.setCellWidth(20);

	while (window.isOpen())
	{
		sf::sleep(sf::milliseconds(100));

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyPressed)
				switch (event.key.code)
				{
				case sf::Keyboard::Right:
					tet.right();
					if (gr.checkCollision(tet))
						tet.left();
					break;

				case sf::Keyboard::Left:
					tet.left();
					if (gr.checkCollision(tet))
						tet.right();
					break;
				}
		}
		
		renderer.start();

		static int counter = 0;

		if (counter > 2)
		{
			tet.setPosition(tet.getPosition() + sf::Vector2<int>(0, 1));

			if (gr.checkCollision(tet))
			{
				tet.setPosition(tet.getPosition() + sf::Vector2<int>(0, -1));
				gr.add(tet);
				tet.reset(10);
			}
			else
			{
				renderer.submit(tet);
			}
			counter = 0;
		}
		else
		{
			renderer.submit(tet);
		}

		counter++;

		gr.update();

		renderer.end();

		window.clear();
		renderer.render(window, gr);
		window.display();
	}

	return 0;
}