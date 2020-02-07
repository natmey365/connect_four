// Top level C++ file

#include <iostream>
#include "game.h"
#include "randomPlayer.h"

int main()
{
	Game game(new RandomPlayer, new RandomPlayer);
}
