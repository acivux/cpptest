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
	sf::RenderWindow window(sf::VideoMode(400, 20*15), "SFML works!", sf::Style::Titlebar | sf::Style::Close);
	sf::Clock gameClock;
	Board board(20, 10, 15);
	GameState gameState(20, 10);
	gameState.GenerateNewShape();

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

			int squash = gameState.GetSquashRow();
			while (squash > -1)
			{
 				gameState.SquashRow(squash);
				board.SquashRow(squash);
				squash = gameState.GetSquashRow();
			}

			if (!gameState.StepDown())
			{
				gameState.LockShape();
				board.LockShape(gameState.GetCurrentShape(), gameState.GetCurrentShapeColor(), gameState.GetActiveRow(), gameState.GetActiveCol());
				if (!gameState.GenerateNewShape())
				{
					return 0;
				}
				board.DrawShape(gameState.GetCurrentShape(), gameState.GetCurrentShapeColor(), gameState.GetActiveRow(), gameState.GetActiveCol());
			}
			gameClock.restart();
		}
		board.DrawShape(gameState.GetCurrentShape(), gameState.GetCurrentShapeColor(), gameState.GetActiveRow(), gameState.GetActiveCol());
		window.clear(sf::Color::White);
		window.draw(board);
		window.display();
	}

	return 0;
}
