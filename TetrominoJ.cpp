#include "TetrominoJ.h"



TetrominoJ::TetrominoJ()
{
	SetColor(sf::Color(0, 128, 255));
	Name = "J";
	std::vector<std::vector<bool>> shape;
	shape.resize(2);
	shape[0] = { true, true, true };
	shape[1] = { false, false, true };
	SetShape(shape);
}


TetrominoJ::~TetrominoJ()
{
}
