// C++ file defining the Peice test

#include "pieceTest.h"

int main(int argc, char* argv[])
{
	bool white = true;
	bool black = false;

	Piece whitePiece(white);
	if(!whitePiece.getIsWhite())
	{
		std::cout << "whitePiece is not white!\n";
		return 1;
	}

	Piece blackPiece(black);
	if(blackPiece.getIsWhite())
	{
		std::cout << "blackPiece is not white!\n";
		return 1;
	}

	return 0;
}
