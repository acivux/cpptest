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
	void GoLeft();
	void GoRight();
	void RotateRight();
	void RotateLeft();
	void StepDown();
	void ShootDown();
	int GetActiveRow();
	int GetActiveCol();
private:
	std::vector<std::vector<bool>> m_gameGrid;
	int m_activeRow = 0;
	int m_activeCol = 0;
	bool m_shapeChanged = false;
	TetrominoShape m_currentTetromino;
	TetrominoShape m_previousTetromino;
};

