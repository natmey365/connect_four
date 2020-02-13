// Top level C++ file

#include <iostream>
#include "game.h"
#include "board.h"
#include "space.h"
#include "piece.h"
#include "player.h"
#include "randomPlayer.h"

int main()
{
	Game game(new RandomPlayer, new RandomPlayer);
}
