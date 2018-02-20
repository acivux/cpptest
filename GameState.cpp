#include <cmath>
#include "GameState.h"
#include <TetrominoL.h>
#include <TetrominoJ.h>
#include <TetrominoI.h>
#include <TetrominoO.h>
#include <TetrominoS.h>
#include <TetrominoT.h>
#include <TetrominoZ.h>

GameState::GameState(int rows, int cols)
{
	m_gameGrid.resize(rows);
	for (int i = 0; i < static_cast<int>(m_gameGrid.size()); i++)
		m_gameGrid[i].resize(cols);

	m_currentTetromino = TetrominoL();
	m_activeCol = (m_gameGrid[0].size() / 2) - (m_currentTetromino.GetShapeCols() / 2) - 1 ;
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
	int newCol = m_activeCol - 1;
	if (!IsCollision(m_activeRow, newCol))
		m_activeCol = newCol;

}

void GameState::GoRight()
{
	int newCol = m_activeCol + 1;
	if (!IsCollision(m_activeRow, newCol))
		m_activeCol = newCol;
}

void GameState::RotateRight()
{
	m_currentTetromino.RotateRight();
	if (IsCollision(m_activeRow, m_activeCol))
		m_currentTetromino.RotateLeft();
}

void GameState::RotateLeft()
{
	m_currentTetromino.RotateLeft();
	if (IsCollision(m_activeRow, m_activeCol))
		m_currentTetromino.RotateRight();
}

bool GameState::StepDown()
{
	int newRow = m_activeRow + 1;
	if (!IsCollision(newRow, m_activeCol))
	{
		m_activeRow = newRow;
		return true;
	}
	return false;
}

void GameState::ShootDown()
{
	int newRow = m_activeRow + 1;
	while (!IsCollision(newRow, m_activeCol))
		newRow++;
	
	m_activeRow = newRow - 1;
}

void GameState::LockShape()
{
	for (int rows = 0; rows < m_currentTetromino.GetShapeRows(); rows++)
	{
		for (int cols = 0; cols < m_currentTetromino.GetShapeCols(); cols++)
		{
			if (m_currentTetromino.GetShape()[rows][cols])
				m_gameGrid[m_activeRow + rows][m_activeCol + cols] = true;
		}
	}
}

int GameState::GetActiveRow()
{
	return m_activeRow;
}

int GameState::GetActiveCol()
{
	return m_activeCol;
}

bool GameState::GenerateNewShape()
{
	int randomNumber = rand() % 7;
	if (randomNumber == 0)
		m_currentTetromino = TetrominoJ();
	else if (randomNumber == 1)
		m_currentTetromino = TetrominoL();
	else  if (randomNumber == 2)
		m_currentTetromino = TetrominoI();
	else if (randomNumber == 3)
		m_currentTetromino = TetrominoO();
	else if (randomNumber == 4)
		m_currentTetromino = TetrominoS();
	else if (randomNumber == 5)
		m_currentTetromino = TetrominoT();
	else if (randomNumber == 6)
		m_currentTetromino = TetrominoZ();

	m_activeRow = 0;
	m_activeCol = (m_gameGrid[0].size() / 2) - (m_currentTetromino.GetShapeCols() / 2) - 1;
	return !IsCollision(m_activeRow, m_activeCol);
}

int GameState::GetSquashRow()
{
	for (int rows = m_gameGrid.size() - 1; rows > 0; rows--)
	{
		if (std::all_of(m_gameGrid[rows].begin(), m_gameGrid[rows].end(), [](bool b) { return b == true; }))
			return rows;

		if (std::all_of(m_gameGrid[rows].begin(), m_gameGrid[rows].end(), [](bool b) { return b == false; }))
			return -1;
	}
	return -1;
}

void GameState::SquashRow(int row)
{
	m_score++;

	for (int rows = row; rows > 0; rows--)
		m_gameGrid[rows] = m_gameGrid[rows - 1];
}


bool GameState::IsCollision(int testRow, int testCol)
{
	bool collision = false;

	if (testRow < 0 || testRow + m_currentTetromino.GetShapeRows() > m_gameGrid.size())
	{
		return true;
	}

	if (testCol < 0 || testCol + m_currentTetromino.GetShapeCols() > m_gameGrid[0].size())
	{
		return true;
	}

	for (int rows = 0; rows < m_currentTetromino.GetShapeRows(); rows++)
	{
		for (int cols = 0; cols < m_currentTetromino.GetShapeCols(); cols++)
		{
			if (m_gameGrid[testRow + rows][testCol + cols] && m_currentTetromino.GetShape()[rows][cols])
				return true;
		}
	}

	return false;
}
