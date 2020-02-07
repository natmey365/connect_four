// Header file defining the RandomPlayer class

#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include <stdlib.h>

class RandomPlayer : public Player
{
	public:
		RandomPlayer();
		int move(Board *board);
};

#endif
