// C++ file defining the Player class

#include "humanPlayer.h"

HumanPlayer::HumanPlayer()
{}

int HumanPlayer::move(Board& board)
{
	int column;
	std::cout << "Enter an integer representing the column of your move: ";
	std::cin >> column;
	return column;
}
