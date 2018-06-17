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

	int no = rand() % Constants::NumberOfPoss;

	loadFromPattern(Constants::Patterns::Poss[no], Constants::Color::Poss[no]);
}

void tetris::left()
{
	m_position.x += -1;
}

void tetris::right()
{
	m_position.x += 1;
}

void tetris::up()
{
	m_position.y += 1;
}

void tetris::down()
{
	m_position.y += -1;
}

void tetris::loadFromPattern(const std::string& pattern, sf::Color color)
{
	m_color = color;

	m_blockList.clear();

	int x = 0;
	int y = 0;

	//	0 : is an empty space
	//	1 : is a block
	//	\n : is a new line

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
	}
}

BlockList tetris::getBlocks() const
{
	BlockList result = m_blockList;

	for (Block& b : result)
	{
		b.setPosition(b.getPosition() + m_position);
		b.setColor(m_color);
	}

	return result;
}
