// Header file defining the Space class
#ifndef SPACE_H
#define SPACE_H

#include "piece.h"

class Space
{
	public:
		Space();
		int status();
		int placePiece(bool boolean);

	private:
		Piece *piece;

};

#endif
