// C++ file defining the Board class

#include <iostream>
#include "board.h"
#include "space.h"

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

Board::Board(const Board& rhs)
{
	std::cout << "Started to copy!\n";
	for(int i = 0; i < 6; i++)
	{
		std::cout << "copying\n";
		for(int j = 0; j < 7; j++)
		{
			spaces[i][j] = rhs.spaces[i][j];
		}
	}
}

void Board::print()
{
        for(int i = 0; i < 6; i++)
        {
                for(int j = 0; j < 7; j++)
                {
                        if(this->spaceStatus(i, j) == 1)
                                std::cout << "W";
                        else if(this->spaceStatus(i, j) == -1)
                                std::cout << "B";
                        else
                                std::cout << " ";
                }
                std::cout << std::endl;
        }
        std::cout << std::endl;
}
