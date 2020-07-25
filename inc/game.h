// Header file defining the Game class

#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string.h>
#include "board.h"
#include "player.h"

class Game
{
	public:
		Game(Player* player1, Player* player2, bool boolean);
		std::string  play();

	private:
		bool        verbose;
		bool        whitesTurn;
		bool        gameOver;
		int         winner;
		Board       board;
		Player*     whitePlayer;
		Player*     blackPlayer;
		Player*     playerToMove;
		std::string gameData;

		void   printBoard();
		int    checkWinner();
		bool   boardFull();
		void   move();
};

#endif
