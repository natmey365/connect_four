// Header file defining the Player class

#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

class Player
{
	public:
		virtual int move(Board *board) = 0;
};

#endif
