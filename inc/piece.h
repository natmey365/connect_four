// Header file defining the Piece class

#ifndef PIECE_H
#define PIECE_H

class Piece
{
	public:
		Piece();
		Piece(bool boolean);
		bool getIsWhite();

	private:
		bool isWhite;
};

#endif
