#include "TetrominoT.h"



TetrominoT::TetrominoT()
{
	SetColor(sf::Color(127, 0, 255));
	Name = "T";
	std::vector<std::vector<bool>> shape;
	shape.resize(2);
	shape[0] = { true, true, true };
	shape[1] = { false, true, false };
	SetShape(shape);
}


TetrominoT::~TetrominoT()
{
}
