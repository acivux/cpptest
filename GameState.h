#pragma once
#include "TetrominoShape.h"
#include "TetrominoL.h"
#include "Block.h"

class GameState
{
public:
	GameState(int rows, int cols);
	~GameState();
	void SetCurrentTetromino(TetrominoShape);
	std::vector<std::vector<bool>> GetCurrentShape();
	sf::Color GetCurrentShapeColor();
	std::vector<std::vector<bool>> GetPreviousShape();
	void GoLeft();
	void GoRight();
	void RotateRight();
	void RotateLeft();
	bool StepDown();
	void ShootDown();
	void LockShape();
	int GetActiveRow();
	int GetActiveCol();
	bool GenerateNewShape();
	int GetSquashRow();
	void SquashRow(int row);
private:
	std::vector<std::vector<bool>> m_gameGrid;
	int m_activeRow = 0;
	int m_activeCol = 0;
	int m_score = 0;
	TetrominoShape m_currentTetromino;
	TetrominoShape m_previousTetromino;
	bool IsCollision(int row, int col);
};

