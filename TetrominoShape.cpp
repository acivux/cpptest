#include "TetrominoShape.h"

TetrominoShape::TetrominoShape()
{
}

TetrominoShape::~TetrominoShape()
{
}

void TetrominoShape::SetColor(sf::Color newColor)
{
	m_color = newColor;
}

sf::Color TetrominoShape::GetColor()
{
	return m_color;
}

void TetrominoShape::SetShape(std::vector<std::vector<bool>> shapeData)
{
	m_shapeData = shapeData;
}

int TetrominoShape::GetShapeRows()
{
	return static_cast<int>(m_shapeData.size());
}

int TetrominoShape::GetShapeCols()
{
	return static_cast<int>(m_shapeData[0].size());
}

std::vector<std::vector<bool>> TetrominoShape::GetShape()
{
	return m_shapeData;
}
