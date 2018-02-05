#include <SFML/Graphics.hpp>
#include "Board.h"
#include "Block.h"

Board::Board(int rowcount, int colcount, int block_size)
{
	columns = colcount;
	rows = rowcount;
	blocksize = block_size;
	m_displayGrid.resize(rows);

	for (int i = 0; i < rowcount; i++)
		m_displayGrid[i].resize(colcount);

	for (int row = 0; row < m_displayGrid.size(); row++)
	{
		for (int col = 0; col < m_displayGrid[row].size(); col++)
		{
			Block b(static_cast<float>(row * blocksize), static_cast<float>(col * blocksize), static_cast<float>(blocksize));
			m_displayGrid[row][col] = b;
		}
	}
}

Board::~Board()
{
}

void Board::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
	states.transform *= getTransform();
	for (int row = 0; row < m_displayGrid.size(); row++)
	{
		for (int col = 0; col < m_displayGrid[row].size(); col++)
		{
			target.draw(m_displayGrid[row][col], states);
		}
	}
}

void Board::SetBlockColor(int row, int col, sf::Color newcolor)
{
	m_displayGrid[row][col].SetColor(newcolor);
}

void Board::EraseShape(std::vector<std::vector<bool>> shape, int activeRow, int activeCol)
{
	DrawShape(shape, sf::Color::White, activeRow, activeCol);
}

void Board::DrawShape(std::vector<std::vector<bool>> shape, sf::Color color, int activeRow, int activeCol)
{
	for (int row = 0; row < shape.size(); row++)
	{
		for (int col = 0; col < shape[0].size(); col++)
		{
			if (shape[row][col])
				SetBlockColor(activeRow + row, activeCol + col, color);
		}
	}
}
