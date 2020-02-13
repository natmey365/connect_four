// Header file defining the RandomPlayer class

#ifndef RANDOMPLAYER_H
#define RANDOMPLAYER_H

#include <stdlib.h>
#include <time.h>
#include "game.h"
#include "board.h"
#include "space.h"
#include "piece.h"
#include "player.h"

class RandomPlayer : public Player
{
	public:
		RandomPlayer();
		int move(Board *board);
};

#endif
