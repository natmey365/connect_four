// Header file defining the Board class
#ifndef BOARD_H
#define BOARD_H

#include "space.h"

class Board
{
	public:
		Space spaces[7][6];

		Board();
		bool columnFull(int j);

	private:

};

#endif
