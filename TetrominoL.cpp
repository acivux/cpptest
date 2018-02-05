#pragma once
#include "TetrominoL.h"
#include <vector>

TetrominoL::TetrominoL()
{
	SetColor(sf::Color(255, 128, 0));
	Name = "L";
	std::vector<std::vector<bool>> shape;
	shape.resize(2);
	shape[0] = { true, true, true };
	shape[1] = { true, false, false };
	SetShape(shape);
}


TetrominoL::~TetrominoL()
{
}
