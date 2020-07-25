// C++ file defining the Board class

#include <iostream>
#include "board.h"
#include "space.h"

Board::Board()
{}

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
	int status = spaces[i][j].status();
	return status;
}

void Board::print()
{
        for(int i = 0; i < 6; i++)
        {
                for(int j = 0; j < 7; j++)
                {
                        if(spaces[i][j].status() == 1)
                                std::cout << "W";
                        else if(spaces[i][j].status() == -1)
                                std::cout << "B";
                        else
                                std::cout << " ";
                }
                std::cout << std::endl;
        }
        std::cout << std::endl;
}

bool Board::full()
{
	if((spaces[0][0].status() != 0) &&
           (spaces[1][0].status() != 0) &&
           (spaces[2][0].status() != 0) &&
           (spaces[3][0].status() != 0) &&
           (spaces[4][0].status() != 0) &&
           (spaces[5][0].status() != 0) &&
           (spaces[6][0].status() != 0))
		return true;
	else
		return false;
}
