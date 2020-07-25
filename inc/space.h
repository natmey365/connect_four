// Header file defining the Space class
#ifndef SPACE_H
#define SPACE_H

#include <iostream>

class Space
{
	public:
		Space();
		int status();
		int placePiece(bool boolean);

	private:
		bool occupied;
		bool isWhite;

};

#endif
