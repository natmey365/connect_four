// Top level C++ file

#include <iostream>
#include "game.cpp"

int main()
{
	Game game(new RandomPlayer, new RandomPlayer);
}
