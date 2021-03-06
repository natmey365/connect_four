// Top level C++ file

#include "main.h"

int main(int argc, char* argv[])
{
	bool verbose;
	argParse(argc, argv, verbose);

	Player* player1 = new RandomPlayer;
	//Player* player1 = new HumanPlayer;
	//Player* player1 = new EvaluativeNNPlayer(&nn);

	Player* player2 = new RandomPlayer;
	//Player* player2 = new HumanPlayer;
	//Player* player2 = new EvaluativeNNPlayer(&nn);

	Game game(player1, player2, verbose);
	std::string gameData = game.play();
	if(verbose)
		std::cout << "Game data: " << gameData << std::endl;
	return 0;
}
