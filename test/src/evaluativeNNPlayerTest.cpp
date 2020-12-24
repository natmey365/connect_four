// Top level C++ file

#include "main.h"

int main(int argc, char* argv[])
{
	bool verbose;
	argParse(argc, argv, verbose);

	Player* player1 = new RandomPlayer;

	int numLayers = 4;
	int shape[4] = {42*3, 42*3*3, 42*3*3, 1};
	NeuralNetwork nn(numLayers, shape, &sigmoid);
	Player* player2 = new EvaluativeNNPlayer(&nn);

	Game game(player1, player2, verbose);
	std::string gameData = game.play();
	if(verbose)
		std::cout << "Game data: " << gameData << std::endl;
	return 0;
}
