#include "tetris.hpp"
#include "Objects.hpp"
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

	loadFromPattern(Constants::Patterns::Poss[no], Constants::Color::Poss[no], Constants::Origin::Poss[no]);
}

void tetris::left()
{
	m_position.x += -1;
}

void tetris::right()
{
	m_position.x += 1;
}

void tetris::down()
{
	m_position.y += 1;
}

void tetris::rotate(RotationDirection dir)
{
	//x' = x cos f - y sin f
	//y' = y cos f + x sin f

	if (m_origin.x == -1 || m_origin.y == -1)
		return;

	int mul = (dir==RotationDirection::ClockWise) ? 1 : -1;

	for (Block& b : m_blockList)
	{
		sf::Vector2i oldPos = b.getPosition();
		oldPos -= m_origin;
		sf::Vector2i newPos = { -mul*oldPos.y, +mul*oldPos.x };
		newPos += m_origin;

		b.setPosition(newPos);
	}
}

void tetris::up()
{
	m_position.y += -1;
}

void tetris::setColor(sf::Color value)
{
	m_color = value;
}

sf::Color tetris::getColor() const
{
	return m_color;
}

void tetris::setPosition(sf::Vector2i position)
{
	m_position = position;
}

sf::Vector2i tetris::getPosition() const
{
	return m_position;
}

void tetris::loadFromPattern(const std::string& pattern, sf::Color color, sf::Vector2i origin)
{
	m_color = color;
	m_origin = origin;

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
