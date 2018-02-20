#include "Block.h"
#include <SFML/Graphics.hpp>


Block::Block()
{
	InitBlock();
	size = defaultsize;
}

Block::Block(float yoffset, float xoffset, float blocksize)
{
	size = blocksize;
	x = xoffset;
	y = yoffset;
	InitBlock();
}

void Block::SetColor(sf::Color newcolor)
{
	block.setFillColor(newcolor);
}

sf::Color Block::GetColor()
{
	return block.getFillColor();
}

void Block::InitBlock()
{
	linecolor = sf::Color::Black;
	fillcolor = sf::Color::White;
	block.setSize(sf::Vector2f(size, size));
	block.setPosition(sf::Vector2f(x, y));
	block.setOutlineThickness(-1);
	block.setOutlineColor(linecolor);
	block.setFillColor(fillcolor);
}

void Block::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	target.draw(block, states);
}

Block::~Block()
{
}
