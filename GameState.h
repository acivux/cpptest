#pragma once
#include "TetrominoShape.h"
#include "TetrominoL.h"
#include "Block.h"

class GameState
{
public:
	GameState(TetrominoShape newTetromino, int rows, int cols);
	~GameState();
	void SetCurrentTetromino(TetrominoShape);
	std::vector<std::vector<bool>> GetCurrentShape();
	sf::Color GetCurrentShapeColor();
	std::vector<std::vector<bool>> GetPreviousShape();
	int GetActiveRow();
	int GetActiveCol();
	bool ShapeChanged();
private:
	std::vector<std::vector<bool>> m_gameGrid;
	int m_activeRow, m_activeCol = 0;
	bool m_shapeChanged = false;
	TetrominoShape m_currentTetromino;
	TetrominoShape m_previousTetromino;
};

