// Header file defining the Player class

#ifndef PLAYER_H
#define PLAYER_H

#include "board.h"

class Player
{
	public:
		virtual int move(const Board& board) = 0;
		void setIsWhite(bool b);
		bool getIsWhite();

	protected:
		bool isWhite;
};

#endif
