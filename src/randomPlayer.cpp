// C++ file defining the RanmdomPlayer class

#include "randomPlayer.h"

RandomPlayer::RandomPlayer()
{
        srand(time(NULL));
}

int RandomPlayer::move(Board *board)
{
        return rand() % 7;
}
