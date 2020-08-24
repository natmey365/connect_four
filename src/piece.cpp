// C++ file defining the Piece class

#include "piece.h"
#include <iostream>

Piece::Piece()
{}

Piece::Piece(bool boolean)
{
	isWhite = boolean;
}

bool Piece::getIsWhite()
{
	return isWhite;
}
