#include <SFML/Graphics.hpp>
#include <cmath>
#include <Board.h>
#include <GameState.h>
#include <TetrominoL.h>
#include <TetrominoJ.h>
#include <TetrominoI.h>
#include <TetrominoO.h>
#include <TetrominoS.h>
#include <TetrominoT.h>
#include <TetrominoZ.h>

int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 800), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
	sf::Clock gameClock;
	Board board(20, 10, 15);
	GameState gameState(TetrominoL(), 20, 10);
	TetrominoL lShape;
	TetrominoJ jShape;
	TetrominoI iShape;
	TetrominoO oShape;
	TetrominoS sShape;
	TetrominoT tShape;
	TetrominoZ zShape;
	//board.DrawShape(gameState.GetCurrentShape(), gameState.GetCurrentShapeColor(), gameState.GetActiveRow(), gameState.GetActiveCol());
	//board.DrawShape(jShape.GetShape(), jShape.GetColor(), 3, 0);
	//board.DrawShape(iShape.GetShape(), iShape.GetColor(), 0, 5);
	//board.DrawShape(oShape.GetShape(), oShape.GetColor(), 3, 5);
	//board.DrawShape(sShape.GetShape(), sShape.GetColor(), 6, 0);
	//board.DrawShape(tShape.GetShape(), tShape.GetColor(), 6, 5);
	//board.DrawShape(zShape.GetShape(), zShape.GetColor(), 9, 0);


	gameState.SetCurrentTetromino(lShape);

	//int randomNumber = rand() % 7;
	//if (randomNumber == 0)
	//	gameState.SetCurrentTetromino(jShape);
	//else if (randomNumber == 1)
	//	gameState.SetCurrentTetromino(lShape);
	//else  if (randomNumber == 2)
	//	gameState.SetCurrentTetromino(iShape);
	//else if (randomNumber == 3)
	//	gameState.SetCurrentTetromino(oShape);
	//else if (randomNumber == 4)
	//	gameState.SetCurrentTetromino(sShape);
	//else if (randomNumber == 5)
	//	gameState.SetCurrentTetromino(tShape);
	//else if (randomNumber == 6)
	//	gameState.SetCurrentTetromino(zShape);

	while (window.isOpen())
	{
		board.EraseShape(gameState.GetCurrentShape(), gameState.GetActiveRow(), gameState.GetActiveCol());

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Left)
				gameState.GoLeft();
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Right)
				gameState.GoRight();
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space)
				gameState.ShootDown();
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Up)
				gameState.RotateRight();
			if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Down)
				gameState.RotateLeft();
		}
		
		sf::Time elapsedTime = gameClock.getElapsedTime();
		if (elapsedTime.asMilliseconds() > 1000)
		{
			board.EraseShape(gameState.GetCurrentShape(), gameState.GetActiveRow(), gameState.GetActiveCol());
			gameState.StepDown();
		//	randomNumber = rand() % 7;
		//	board.EraseShape(gameState.GetCurrentShape(), gameState.GetActiveRow(), gameState.GetActiveCol());

		//	if (randomNumber == 0)
		//		gameState.SetCurrentTetromino(jShape);
		//	else if (randomNumber == 1)
		//		gameState.SetCurrentTetromino(lShape);
		//	else  if (randomNumber == 2)
		//		gameState.SetCurrentTetromino(iShape);
		//	else if (randomNumber == 3)
		//		gameState.SetCurrentTetromino(oShape);
		//	else if (randomNumber == 4)
		//		gameState.SetCurrentTetromino(sShape);
		//	else if (randomNumber == 5)
		//		gameState.SetCurrentTetromino(tShape);
		//	else if (randomNumber == 6)
		//		gameState.SetCurrentTetromino(zShape);

		//	board.DrawShape(gameState.GetCurrentShape(), gameState.GetCurrentShapeColor(), gameState.GetActiveRow(), gameState.GetActiveCol());
			gameClock.restart();
		}
		board.DrawShape(gameState.GetCurrentShape(), gameState.GetCurrentShapeColor(), gameState.GetActiveRow(), gameState.GetActiveCol());
		window.clear(sf::Color::White);
		window.draw(board);
		window.display();
	}

	return 0;
}
