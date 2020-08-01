// C++ file defining the Piece class

#include "piece.h"
#include <iostream>

Piece::Piece()
{}

Piece::Piece(bool boolean)
{
	is_white = boolean;
}

bool Piece::isWhite()
{
	return is_white;
}
