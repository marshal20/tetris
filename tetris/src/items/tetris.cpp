#include "tetris.h"
#include "Objects.h"
#include <time.h>

tetris::tetris()
{
}


tetris::~tetris()
{
}

void tetris::reset(int width)
{
	srand(time(NULL));

	m_position = { rand() % (width - 4) , -1 };

	static const char* pos_pat[] = { Pattern::I , Pattern::J , Pattern::L ,
									Pattern::O ,Pattern::S ,Pattern::T, Pattern::Z };

	static const sf::Color pos_color[] = { sf::Color::Cyan , sf::Color::Blue , sf::Color(255, 127, 39),
								sf::Color::Yellow , sf::Color::Green , sf::Color(163, 73, 164) , sf::Color::Red };

	int no = rand() % 7;

	loadFromPattern(pos_pat[no], pos_color[no]);
}

void tetris::left()
{
	m_position.x += -1;
}

void tetris::right()
{
	m_position.x += 1;
}

void tetris::setColor(sf::Color value)
{
	m_color = value;
}

sf::Color tetris::getColor() const
{
	return m_color;
}

void tetris::setPosition(sf::Vector2<int> position)
{
	m_position = position;
}

sf::Vector2<int> tetris::getPosition() const
{
	return m_position;
}

void tetris::loadFromPattern(std::string pattern, sf::Color color)
{
	m_color = color;

	m_blockList.clear();

	int x = 0;
	int y = 0;

	for (char c : pattern)
	{
		if (c == '0')
		{
			x++;
		}
		else if(c == '1')
		{
			m_blockList.push_back(Block({ x,y }, sf::Color::Blue));

			x++;
		}
		else if (c == '\n')
		{
			x = 0;
			y++;
		}
		else
		{
			// TODO: Handle error
		}
	}
}

std::vector<Block> tetris::getBlocks() const
{
	std::vector<Block> result = m_blockList;

	for (int i = 0; i < result.size(); i++)
	{
		result[i].m_position += m_position;
		result[i].m_color = m_color;
	}

	return result;
}
