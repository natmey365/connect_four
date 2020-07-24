// C++ file defining the Game class

#include <iostream>
#include "game.h"
#include "board.h"
#include "player.h"

Game::Game(Player *player1, Player *player2) : whitesTurn(true), winner(0), board(new Board)
{
	whitePlayer = player1;
	blackPlayer = player2;
	while(winner == 0)	// Game loop
	{
		printBoard();	
		winner = checkWinner();
		if(winner == 1)
			std::cout << "White Wins!\n";
		else if(winner == -1)
			std::cout << "Black Wins\n";
		else
			move();
	}
}

void Game::printBoard()
{
	board->print();
}

int Game::checkWinner()
{
	int spaceStatus;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if((spaceStatus = board->spaceStatus(i, j)) == 0)
				continue;
			if(i+3 < 6)
			{
				if(spaceStatus == board->spaceStatus(i+1, j) &&
				   spaceStatus == board->spaceStatus(i+2, j) &&
				   spaceStatus == board->spaceStatus(i+3, j))
					return spaceStatus;
			}
			if(i+3 < 6 && j-3 >= 0)
			{
				if(spaceStatus == board->spaceStatus(i+1, j-1) &&
 				   spaceStatus == board->spaceStatus(i+2, j-2) &&
 				   spaceStatus == board->spaceStatus(i+3, j-3))
 					return spaceStatus;
			}
			if(j-3 >= 0)
			{
                                if(spaceStatus == board->spaceStatus(i, j-1) &&
                                   spaceStatus == board->spaceStatus(i, j-2) &&
                                   spaceStatus == board->spaceStatus(i, j-3))
                                        return spaceStatus;
			}
                        if(i-3 >= 0 && j-3 >= 0)
                        {
                                if(spaceStatus == board->spaceStatus(i-1, j-1) &&
                                   spaceStatus == board->spaceStatus(i-2, j-2) &&
                                   spaceStatus == board->spaceStatus(i-3, j-3))
                                        return spaceStatus;
                        }
                        if(i-3 >= 0)
                        {
                                if(spaceStatus == board->spaceStatus(i-1, j) &&
                                   spaceStatus == board->spaceStatus(i-2, j) &&
                                   spaceStatus == board->spaceStatus(i-3, j))
                                        return spaceStatus;
                        }
                        if(i-3 >= 0 && j+3 < 7)
                        {
                                if(spaceStatus == board->spaceStatus(i-1, j+1) &&
                                   spaceStatus == board->spaceStatus(i-2, j+2) &&
                                   spaceStatus == board->spaceStatus(i-3, j+3))
                                        return spaceStatus;
                        }
                        if(j+3 < 7)
                        {
                                if(spaceStatus == board->spaceStatus(i, j+1) &&
                                   spaceStatus == board->spaceStatus(i, j+2) &&
                                   spaceStatus == board->spaceStatus(i, j+3) )
                                        return spaceStatus;
                        }
                        if(i+3 < 6 && j+3 < 7)
                        {
                                if(spaceStatus == board->spaceStatus(i+1, j+1) &&
                                   spaceStatus == board->spaceStatus(i+2, j+2) &&
                                   spaceStatus == board->spaceStatus(i+3, j+3) )
                                        return spaceStatus;
                        }
		}
	}
	return 0;
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
