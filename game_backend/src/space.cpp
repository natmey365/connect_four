// C++ file defining the Space class

#include <iostream>
#include "space.h"
#include "piece.cpp"

Space::Space() : piece(0)
{
}

int Space::status()
{
	if(piece == NULL)
		return 0;
	else if(piece->isWhite())
		return 1;
	else
		return -1;
}
int Space::placePiece(bool boolean)
{
	if(piece != NULL)
		return 1;
	piece = new Piece(boolean);
	return 0;
}
