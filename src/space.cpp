// C++ file defining the Space class

#include "space.h"

Space::Space() : piece(0)
{}

Space::Space(const Space& original)
{
	if(original.piece != NULL)
	{
		piece = new Piece;
		memcpy(piece, original.piece, sizeof(Piece));
	}
	else
		piece = 0;
}

Space::~Space()
{
	delete piece;
}

int Space::status() const
{
	if(piece == NULL)
		return 0;
	else if(piece->getIsWhite())
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
