#include "O.h"



O::O()
{
	setPosition({ 0,0 });
	m_blockList.push_back(Block({ 0, 0 }, sf::Color::Yellow));
	m_blockList.push_back(Block({ 0, 1 }, sf::Color::Yellow));
	m_blockList.push_back(Block({ 1, 1 }, sf::Color::Yellow));
	m_blockList.push_back(Block({ 1, 0 }, sf::Color::Yellow));
	setColor(sf::Color::Yellow);
}


O::~O()
{
}
