// C++ file defining the Game class

#include <iostream>
#include "game.h"
#include "board.cpp"
#include "player.cpp"

Game::Game(Player *player1, Player *player2) : whitesTurn(true), board(new Board)
{
	whitePlayer = player1;
	blackPlayer = player2;
	while(1)	// Game loop
	{
		printBoard();
		if(checkWinner() == 1)
		{
			std::cout << "White Wins!\n";
			break;
		}
		else if(checkWinner() == -1)
		{
			std::cout << "Black Wins\n";
			break;
		}
		else
		{
			move();
		}
	}
}

void Game::printBoard()
{
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if(board->spaceStatus(i, j) == 1)
				std::cout << "W";
			else if(board->spaceStatus(i, j) == -1)
				std::cout << "B";
			else
				std::cout << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int Game::checkWinner()
{
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if(i+3 < 6)
			{
				if(board->spaceStatus(i, j) == board->spaceStatus(i+1, j) &&
				   board->spaceStatus(i, j) == board->spaceStatus(i+2, j) &&
				   board->spaceStatus(i, j) == board->spaceStatus(i+3, j) )
					return board->spaceStatus(i, j);
			}
			if(i+3 < 6 && j-3 >= 0)
			{
				if(board->spaceStatus(i, j) == board->spaceStatus(i+1, j-1) &&
 				   board->spaceStatus(i, j) == board->spaceStatus(i+2, j-2) &&
 				   board->spaceStatus(i, j) == board->spaceStatus(i+3, j-3) )
 					return board->spaceStatus(i, j);
			}
			if(j-3 >= 0)
			{
                                if(board->spaceStatus(i, j) == board->spaceStatus(i, j-1) &&
                                   board->spaceStatus(i, j) == board->spaceStatus(i, j-2) &&
                                   board->spaceStatus(i, j) == board->spaceStatus(i, j-3) )
                                        return board->spaceStatus(i, j);
			}
                        if(i-3 >= 0 && j-3 >= 0)
                        {
                                if(board->spaceStatus(i, j) == board->spaceStatus(i-1, j-1) &&
                                   board->spaceStatus(i, j) == board->spaceStatus(i-2, j-2) &&
                                   board->spaceStatus(i, j) == board->spaceStatus(i-3, j-3) )
                                        return board->spaceStatus(i, j);
                        }
                        if(i-3 >= 0)
                        {
                                if(board->spaceStatus(i, j) == board->spaceStatus(i-1, j) &&
                                   board->spaceStatus(i, j) == board->spaceStatus(i-2, j) &&
                                   board->spaceStatus(i, j) == board->spaceStatus(i-3, j) )
                                        return board->spaceStatus(i, j);
                        }
                        if(i-3 >= 0 && j+3 < 7)
                        {
                                if(board->spaceStatus(i, j) == board->spaceStatus(i-1, j+1) &&
                                   board->spaceStatus(i, j) == board->spaceStatus(i-2, j+2) &&
                                   board->spaceStatus(i, j) == board->spaceStatus(i-3, j+3) )
                                        return board->spaceStatus(i, j);
                        }
                        if(j+3 < 7)
                        {
                                if(board->spaceStatus(i, j) == board->spaceStatus(i, j+1) &&
                                   board->spaceStatus(i, j) == board->spaceStatus(i, j+2) &&
                                   board->spaceStatus(i, j) == board->spaceStatus(i, j+3) )
                                        return board->spaceStatus(i, j);
                        }
                        if(i+3 < 6 && j+3 < 7)
                        {
                                if(board->spaceStatus(i, j) == board->spaceStatus(i+1, j+1) &&
                                   board->spaceStatus(i, j) == board->spaceStatus(i+2, j+2) &&
                                   board->spaceStatus(i, j) == board->spaceStatus(i+3, j+3) )
                                        return board->spaceStatus(i, j);
                        }
			return 0;
		}
	}
}

void Game::move()
{
	if(whitesTurn)
	{
		while(board->placePiece(whitePlayer->move(board), whitesTurn))
		{
			std::cout << "Invalid Move!\n";
		}
		whitesTurn = false;
	}
	else
	{
	        while(board->placePiece(blackPlayer->move(board), whitesTurn))
 		{
 			std::cout << "Invalid Move!\n";
		}
		whitesTurn = true;
	}
}
