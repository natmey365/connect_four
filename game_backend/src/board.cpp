// C++ file defining the Board class

#include <iostream>
#include "board.h"
#include "space.cpp"

Board::Board()
{
}

bool Board::columnFull(int j)
{
	if(spaces[0][j].status() == 0)
		return false;
	return true;
}

int Board::placePiece(int j, bool boolean)
{	
	if(j > 6)
		return 1;
	for(int i = 5; i >= 0 ; i--)
	{
		if(!spaces[i][j].placePiece(boolean))
			return 0;	// SUCCESS
	}
	return 1;		// FAIL
}

int Board::spaceStatus(int i, int j)
{
	return spaces[i][j].status();
}
