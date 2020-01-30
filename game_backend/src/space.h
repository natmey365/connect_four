// Header file defining the Space class
#ifndef SPACE_H
#define SPACE_H

#include "piece.h"

class Space
{
	public:
		Space();
		bool isBlank();
		void placePiece(bool boolean);

	private:
		Piece *piece;

};

#endif
