#include "TetrominoS.h"



TetrominoS::TetrominoS()
{
	SetColor(sf::Color(0, 255, 0));
	Name = "S";
	std::vector<std::vector<bool>> shape;
	shape.resize(2);
	shape[0] = { false, true, true };
	shape[1] = { true, true, false};
	SetShape(shape);
}


TetrominoS::~TetrominoS()
{
}
