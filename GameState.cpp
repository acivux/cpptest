#include "GameState.h"

GameState::GameState(TetrominoShape newTetromino, int rows, int cols)
{
	m_gameGrid.resize(rows);
	for (int i = 0; i < static_cast<int>(m_gameGrid.size()); i++)
		m_gameGrid[i].resize(cols);

	m_currentTetromino = newTetromino;
}

GameState::~GameState()
{
}

void GameState::SetCurrentTetromino(TetrominoShape newTetromino)
{
	m_previousTetromino = m_currentTetromino;
	m_currentTetromino = newTetromino;
}

std::vector<std::vector<bool>> GameState::GetCurrentShape()
{
	return m_currentTetromino.GetShape();
}

sf::Color GameState::GetCurrentShapeColor()
{
	return m_currentTetromino.GetColor();
}

std::vector<std::vector<bool>> GameState::GetPreviousShape()
{
	return m_previousTetromino.GetShape();
}

void GameState::GoLeft()
{
	if (m_activeCol > 0)
	{
		m_activeCol--;
	}
}

void GameState::GoRight()
{
	if (m_activeCol + m_currentTetromino.GetShapeCols() < m_gameGrid[0].size())
		m_activeCol++;
}

void GameState::RotateRight()
{
	m_currentTetromino.RotateRight();
	if (m_activeRow + m_currentTetromino.GetShapeRows() > m_gameGrid.size())
		m_currentTetromino.RotateLeft();
}

void GameState::RotateLeft()
{
	m_currentTetromino.RotateLeft();
	if (m_activeRow + m_currentTetromino.GetShapeRows() > m_gameGrid.size())
		m_currentTetromino.RotateRight();
}

void GameState::StepDown()
{
	if (m_activeRow + m_currentTetromino.GetShapeRows() < m_gameGrid.size())
		m_activeRow++;
}

void GameState::ShootDown()
{
	m_activeRow = m_gameGrid.size() - m_currentTetromino.GetShapeRows();
}

int GameState::GetActiveRow()
{
	return m_activeRow;
}

int GameState::GetActiveCol()
{
	return m_activeCol;
}
