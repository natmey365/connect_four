// Header file defining the Space class
#ifndef SPACE_H
#define SPACE_H

#include <string.h>
#include <iostream>
#include "piece.h"

class Space
{
	public:
		Space();
		Space(const Space& original);
		~Space();

		int    status();
		int    placePiece(bool boolean);

//	private:
		Piece*   piece;
};

#endif
