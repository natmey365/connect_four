// C++ file defining the Player class

#include "player.h"

RandomPlayer::RandomPlayer()
{
	srand(time(NULL));
}

int RandomPlayer::move(Board *board)
{
	return rand() % 7;
}
