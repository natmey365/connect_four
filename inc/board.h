// Header file defining the Board class
#ifndef BOARD_H
#define BOARD_H

#include "space.h"

class Board
{
	public:
		Board();

		bool columnFull(int j) const;
		int placePiece(int j, bool boolean);
		int spaceStatus(int i, int j) const;
		void print() const;
		bool full() const;

	private:
		Space spaces[6][7];
};

#endif
