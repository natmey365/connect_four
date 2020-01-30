// C++ file defining the Space class

#include <iostream>
#include "space.h"
#include "piece.cpp"

Space::Space() : piece(0)
{
	std::cout << "Space Constructor\n";
}

bool Space::isBlank()
{
	if(piece == NULL)
	{
		std::cout << "blank\n";
		return true;
	}
	return false;
}
void Space::placePiece(bool boolean)
{
	if(piece != NULL)
	{
		delete(piece);
		std::cout << "deleted piece before add\n";
	}
	piece = new Piece(boolean);
	std::cout << "placed piece\n";
}
