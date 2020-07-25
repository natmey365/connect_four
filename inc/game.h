// Header file defining the Game class

#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

class Game
{
	public:
		Game(Player *player1, Player *player2, bool boolean);
		int play();

	private:
		bool    verbose;
		bool    whitesTurn;
		bool    gameOver;
		int     winner;
		Board   board;
		Player* whitePlayer;
		Player* blackPlayer;
		Player* playerToMove;
		char*   gameData;

		void   printBoard();
		int    checkWinner();
		bool   boardFull();
		void   move();
};

#endif
