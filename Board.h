#pragma once
#include <SFML/Graphics.hpp>
#include "Block.h"

class Board : public sf::Transformable, public sf::Drawable
{
public:
	Board(int, int, int);
	void SetBlockColor(int row, int col, sf::Color);
	void EraseShape(std::vector<std::vector<bool>> shape, int activeRow, int activeCol);
	void DrawShape(std::vector<std::vector<bool>> shape, sf::Color, int activeRow, int activeCol);
	void LockShape(std::vector<std::vector<bool>> shape, sf::Color, int activeRow, int activeCol);
	void SquashRow(int row);
	~Board();
private:
	int columns, rows, blocksize;
	std::vector<std::vector<Block>> m_displayGrid;
	int m_currentDisplayRow = 0;
	int m_currentDisplayCol = 0;
	virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};