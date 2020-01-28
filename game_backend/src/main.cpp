// Top level C++ file that creates and runs a Game object

#include <iostream>
#include "game.cpp"

int main()
{
	//Game game;
	//Space space;
	//std::cout << space.isBlank() << std::endl;
	Board board;
	std::cout << !board.columnFull(0) << std::endl;
}
