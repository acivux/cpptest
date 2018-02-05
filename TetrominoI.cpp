#include "TetrominoI.h"



TetrominoI::TetrominoI()
{
	SetColor(sf::Color(0, 255, 255));
	Name = "I";
	std::vector<std::vector<bool>> shape;
	shape.resize(1);
	shape[0] = { true, true, true, true };
	SetShape(shape);
}


TetrominoI::~TetrominoI()
{
}
