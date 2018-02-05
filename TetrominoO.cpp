#include "TetrominoO.h"



TetrominoO::TetrominoO()
{
	SetColor(sf::Color(255, 255, 0));
	Name = "O";
	std::vector<std::vector<bool>> shape;
	shape.resize(2);
	shape[0] = { true, true };
	shape[1] = { true, true };
	SetShape(shape);
}


TetrominoO::~TetrominoO()
{
}
