// Header file defining the Game class

#ifndef GAME_H
#define GAME_H

#include "board.h"
#include "player.h"

class Game
{
	public:
		Game(Player *player1, Player *player2);

	private:
		bool whitesTurn;
		Board *board;
		Player *whitePlayer;
		Player *blackPlayer;
		
		void printBoard();
		int checkWinner();
		void move();
};

#endif
