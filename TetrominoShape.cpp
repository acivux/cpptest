#include "TetrominoShape.h"

TetrominoShape::TetrominoShape()
{
	m_orientation = 0;
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

void TetrominoShape::RotateRight()
{
	SwapRows();
	TransposeShape();
}

void TetrominoShape::RotateLeft()
{
	TransposeShape();
	SwapRows();
}

void TetrominoShape::TransposeShape()
{
	std::vector<std::vector<bool>> newShape(m_shapeData[0].size(), std::vector<bool>(m_shapeData.size()));
	for (size_t i = 0; i < m_shapeData.size(); ++i)
		for (size_t j = 0; j < m_shapeData[0].size(); ++j)
			newShape[j][i] = m_shapeData[i][j];

	m_shapeData = newShape;
}

void TetrominoShape::SwapRows()
{
	for (int rowa = 0, rowb = m_shapeData.size() - 1; rowa < rowb; ++rowa, --rowb) {
		std::vector<bool> x = m_shapeData[rowa];
		m_shapeData[rowa] = m_shapeData[rowb];
		m_shapeData[rowb] = x;
	}
}