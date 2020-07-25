// Header file defining the HumanPlayer class

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "game.h"
#include "board.h"
#include "space.h"
#include "player.h"
#include "piece.h"

class HumanPlayer : public Player
{
	public:
		HumanPlayer();
		int move(Board& board);
};

#endif
