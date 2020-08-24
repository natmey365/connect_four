// C++ file defining the Game class

#include <iostream>
#include "game.h"
#include "board.h"
#include "player.h"

Game::Game(Player* player1, Player* player2, bool _verbose) : verbose(_verbose), whitesTurn(true), winner(0), whitePlayer(player1), blackPlayer(player2), playerToMove(player1)
{
	whitePlayer->setIsWhite(true);
	blackPlayer->setIsWhite(false);
}

std::string Game::play()
{
	while(1)
	{
		if(verbose)
			printBoard();
		winner = checkWinner();
		if(winner != 0)
		{
			if(verbose)
			{
				if(winner == 1)
					std::cout << "White wins!\n";
				else
					std::cout << "Black wins!\n";
			}
			return gameData;
		}
		else if(boardFull())
		{
			if(verbose)
				std::cout << "Board is full - Tie!\n";
			return gameData;
		}
		else
			move();
	}
}

void Game::printBoard()
{
	board.print();
}

int Game::checkWinner()
{
	int spaceStatus;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if((spaceStatus = board.spaceStatus(i, j)) == 0)
				continue;
			if(i+3 < 6)
			{
				if(spaceStatus == board.spaceStatus(i+1, j) &&
				   spaceStatus == board.spaceStatus(i+2, j) &&
				   spaceStatus == board.spaceStatus(i+3, j))
					return spaceStatus;
			}
			if(i+3 < 6 && j-3 >= 0)
			{
				if(spaceStatus == board.spaceStatus(i+1, j-1) &&
 				   spaceStatus == board.spaceStatus(i+2, j-2) &&
 				   spaceStatus == board.spaceStatus(i+3, j-3))
 					return spaceStatus;
			}
			if(j-3 >= 0)
			{
                                if(spaceStatus == board.spaceStatus(i, j-1) &&
                                   spaceStatus == board.spaceStatus(i, j-2) &&
                                   spaceStatus == board.spaceStatus(i, j-3))
                                        return spaceStatus;
			}
                        if(i-3 >= 0 && j-3 >= 0)
                        {
                                if(spaceStatus == board.spaceStatus(i-1, j-1) &&
                                   spaceStatus == board.spaceStatus(i-2, j-2) &&
                                   spaceStatus == board.spaceStatus(i-3, j-3))
                                        return spaceStatus;
                        }
                        if(i-3 >= 0)
                        {
                                if(spaceStatus == board.spaceStatus(i-1, j) &&
                                   spaceStatus == board.spaceStatus(i-2, j) &&
                                   spaceStatus == board.spaceStatus(i-3, j))
                                        return spaceStatus;
                        }
                        if(i-3 >= 0 && j+3 < 7)
                        {
                                if(spaceStatus == board.spaceStatus(i-1, j+1) &&
                                   spaceStatus == board.spaceStatus(i-2, j+2) &&
                                   spaceStatus == board.spaceStatus(i-3, j+3))
                                        return spaceStatus;
                        }
                        if(j+3 < 7)
                        {
                                if(spaceStatus == board.spaceStatus(i, j+1) &&
                                   spaceStatus == board.spaceStatus(i, j+2) &&
                                   spaceStatus == board.spaceStatus(i, j+3) )
                                        return spaceStatus;
                        }
                        if(i+3 < 6 && j+3 < 7)
                        {
                                if(spaceStatus == board.spaceStatus(i+1, j+1) &&
                                   spaceStatus == board.spaceStatus(i+2, j+2) &&
                                   spaceStatus == board.spaceStatus(i+3, j+3) )
                                        return spaceStatus;
                        }
		}
	}
	return 0;
}

bool Game::boardFull()
{
	return board.full();
}

void Game::move()
{
	while(board.placePiece(playerToMove->move(board), whitesTurn))
	{
		if(verbose)
		{
			std::cout << "Invalid Move!\n";
			printBoard();
		}
	}
	std::cout << "done thinking" << std::endl;
	if(whitesTurn)
	{
		whitesTurn = false;
		playerToMove = blackPlayer;
	}
	else
	{
		whitesTurn = true;
		playerToMove = whitePlayer;
	}
}
