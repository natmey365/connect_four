// C++ file defining the Human Player test

#include "humanPlayerTest.h"

int main(int argc, char* argv[])
{
	bool verbose;
	argParse(argc, argv, verbose);

	Player* player1 = new RandomPlayer;
	
	Player* player2 = new HumanPlayer;
	
	Game game(player1, player2, verbose);
	std::string gameData = game.play();
	if(verbose)
		std::cout << "Game data: " << gameData << std::endl;
	return 0;

}

