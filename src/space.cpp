// C++ file defining the Space class

#include <iostream>
#include "space.h"
#include "piece.h"

Space::Space() : piece(0)
{
}

Space::Space(const Space& rhs)
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
