// C++ file defining the Space class

#include "space.h"

Space::Space() : occupied(false)
{}

int Space::status()
{
	if(!occupied)
		return 0;
	else if(isWhite)
		return 1;
	else
		return -1;
}
int Space::placePiece(bool boolean)
{
	if(occupied)
		return 1;
	occupied = true;
	isWhite = boolean;
	return 0;
}
