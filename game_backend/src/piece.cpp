// C++ file defining the Piece class

#include "piece.h"
#include <iostream>

Piece::Piece(bool boolean)
{
	is_white = boolean;
	std::cout << is_white << std::endl;
}

bool Piece::isWhite()
{
	return is_white;
}
