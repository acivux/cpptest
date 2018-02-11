#pragma once
#include <SFML/Graphics.hpp>
#include <Block.h>
#include <vector>
#include <string>

class TetrominoShape
{
public:
	TetrominoShape();
	~TetrominoShape();
	std::string Name;
	void SetColor(sf::Color newColor);
	sf::Color GetColor();
	void SetShape(std::vector<std::vector<bool>> shapeData);
	int GetShapeRows();
	int GetShapeCols();
	std::vector<std::vector<bool>> GetShape();
	void RotateRight();
	void RotateLeft();
private:
	void TransposeShape();
	void SwapRows();
	std::vector<std::vector<bool>> m_shapeData;
	sf::Color m_color;
	int m_orientation;
};

