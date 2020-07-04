// Header file defining the Board class
#ifndef BOARD_H
#define BOARD_H

#include "space.h"

class Board
{
	public:
		Board();
		Board(const Board& rhs);
		bool columnFull(int j);
		int placePiece(int j, bool boolean);
		int spaceStatus(int i, int j);

	private:
		Space spaces[6][7];
};

#endif
