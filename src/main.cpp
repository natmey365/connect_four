// Top level C++ file

#include "main.h"

void func(const Board& board)
{
	Board boards[7];
	for(int i=0; i<7; i++)
	{
		boards[i] = board;
		if(!boards[i].placePiece(i, true)) // Failed
			boards[i].print();
	}
}

int main(int argc, char* argv[])
{
	bool verbose = false;
	for(int i = 1; i < argc; i++)
	{
		if(!strcmp(argv[i], "-v"))
			verbose = true;
	}

	bool isWhite = true;
	Board board;
	func(board);

	Space space1;
	Space space2 = space1;
	space1.placePiece(true);
	std::cout << space1.status() << std::endl;
	std::cout << space2.status() << std::endl;

	int numLayers = 4;
	int shape[4] = {42*3, 42*3*3, 42*3*3, 1};
	NeuralNetwork nn(numLayers, shape, &sigmoid);

	Player* player1 = new RandomPlayer;
	//Player* player1 = new HumanPlayer;
	//Player* player1 = new EvaluativeNNPlayer(&nn);

	//Player* player2 = new RandomPlayer;
	//Player* player2 = new HumanPlayer;
	Player* player2 = new EvaluativeNNPlayer(&nn);

	std::cout << "Created players, playing game\n";
	Game game(player1, player2, verbose);
	std::string gameData = game.play();
	//std::cout << "Game data: " << gameData << std::endl;
}
