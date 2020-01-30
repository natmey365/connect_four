// C++ file defining the Board class

#include <iostream>
#include "board.h"
#include "space.cpp"

Board::Board()
{
	std::cout << "Board Constructor\n";
}

bool Board::columnFull(int j)
{
	for(int i=6; i>=0; i--)
	{
		if(spaces[i][j].isBlank())
			return false;
	}
	return true;
}

int Board::placePiece(int j, bool boolean)
{
	if(!spaces[5][j].isBlank())
		return 1;	// FAIL
	for(int i=4; i>=0; i--)
        {
                if(!spaces[i][j].isBlank())
		{
			spaces[i+1][j].placePiece(boolean);
			return 0;
        	}
	}
	spaces[0][j].placePiece(boolean);
	return 0;
}
