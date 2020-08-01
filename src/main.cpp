// Top level C++ file

#include "main.h"

int main(int argc, char* argv[])
{
	bool verbose = false;
	for(int i = 1; i < argc; i++)
	{
		if(!strcmp(argv[i], "-v"))
			verbose = true;
	}
	
	
/*	Space space1;
	Space space2 = space1;
	space1.placePiece(true);
	space2.placePiece(false);
	std::cout << space1.status() << std::endl;
	std::cout << space2.status() << std::endl;


	Board board1;
	board1.print();
	board1.placePiece(0, true);
	board1.print();
	board1.placePiece(0, true);
	board1.print();
	board1.placePiece(0, true);
	board1.print();
	Board board2;
*/

	int numLayers = 4;
	int shape[4] = {42*3, 42*3*3, 42*3*3, 1};
	NeuralNetwork nn(numLayers, shape, &sigmoid);


	Player* player1 = new RandomPlayer;
	//Player* player1 = new HumanPlayer;
	//Player* player1 = new EvaluativeNNPlayer(&nn);

	Player* player2 = new RandomPlayer;
	//Player* player2 = new HumanPlayer;
	//Player* player2 = new EvaluativeNNPlayer(&nn);

	std::cout << "Created players, playing game\n";
	Game game(player1, player2, verbose);
	std::string gameData = game.play();
	std::cout << "Game data: " << gameData << std::endl;
}
