#include "GameState.h"


GameState::GameState(TetrominoShape newTetromino, int rows, int cols)
{
	m_gameGrid.resize(rows);
	for (int i = 0; i < static_cast<int>(m_gameGrid.size()); i++)
		m_gameGrid.resize(cols);

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

int GameState::GetActiveRow()
{
	return m_activeRow;
}

int GameState::GetActiveCol()
{
	return m_activeCol;
}

bool GameState::ShapeChanged()
{
	return m_shapeChanged;
}
