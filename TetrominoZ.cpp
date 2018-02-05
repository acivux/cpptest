#include "TetrominoZ.h"



TetrominoZ::TetrominoZ()
{
	SetColor(sf::Color(255, 0, 0));
	Name = "Z";
	std::vector<std::vector<bool>> shape;
	shape.resize(2);
	shape[0] = { true, true, false };
	shape[1] = { false, true, true };
	SetShape(shape);
}


TetrominoZ::~TetrominoZ()
{
}
