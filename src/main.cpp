// Top level C++ file

#include "main.h"

int main(int argc, char* argv[])
{
	bool verbose;
	argParse(argc, argv, verbose);

	int numLayers = 4;
	int shape[4] = {42*3, 42*3*3, 42*3*3, 1};
	NeuralNetwork nn(numLayers, shape, &sigmoid);

	float nn_output;
	float nn_inputs[42*3];
	for(int i=0; i<42*3; i++)
	{
		nn_inputs[i] = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
		std::cout << nn_inputs[i] << std::endl;
	}
	nn.forwardProp(nn_inputs, &nn_output);
	std::cout << "output: " << nn_output << std::endl;
	for(int i=0; i<42*3; i++)
        {
                nn_inputs[i] = ((float)rand() / RAND_MAX) - ((float)rand() / RAND_MAX);
        	std::cout << nn_inputs[i] << std::endl;
	}
	nn.forwardProp(nn_inputs, &nn_output);
        std::cout << "output: " << nn_output << std::endl;
/*
	Player* player1 = new RandomPlayer;
	//Player* player1 = new HumanPlayer;
	//Player* player1 = new EvaluativeNNPlayer(&nn);

	//Player* player2 = new RandomPlayer;
	//Player* player2 = new HumanPlayer;
	Player* player2 = new EvaluativeNNPlayer(&nn);

	Game game(player1, player2, verbose);
	std::string gameData = game.play();
	//std::cout << "Game data: " << gameData << std::endl;
*/
}
