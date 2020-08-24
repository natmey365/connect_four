// C++ file defining the EvaluativeNNPlayer class

#include "evaluativeNNPlayer.h"

EvaluativeNNPlayer::EvaluativeNNPlayer(NeuralNetwork* network) : nn(network)
{

}

int EvaluativeNNPlayer::move(const Board& board)
{
	std::cout << "eval player is thinking" << std::endl;
	// Generate and evaluate boards for each of the possible moves
	Board boards[7];
	//float evaluations[7];
	for(int i = 0; i < 7; i++)
	{
//		boards[i] = board;
/*		if(!boards[i].placePiece(i, isWhite)) // Failed
		{
			//evaluations[i] = 0;
			boards[i].print();
		}
		//else
			//evaluations[i] = 0;//nn->forwardProp(boards[i], evaluations[i]);	
	}

/*	// Choose the move with the best evaluation and return it
	float largest;
	int index;
	largest = evaluations[0];
	index = 0;
*/
}
	return rand() % 7;
}
