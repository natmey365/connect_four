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
		if(!spaces[i][j].isBlank())
			return false;
	}
	return true;
}
