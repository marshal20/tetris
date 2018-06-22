#include "pause.hpp"

Pause::Pause()
{
	m_font.loadFromFile("arial.ttf");
}

Pause::~Pause()
{
}

void Pause::input(sf::Event event)
{

}

void Pause::update(float time, float deltaTime)
{

}

void Pause::render(sf::RenderWindow & window)
{
	sf::Text text;

	text.setFont(m_font);
	text.setString("Hello world");
	text.setCharacterSize(24);
	text.setFillColor(sf::Color::Red);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	window.draw(text);
}
