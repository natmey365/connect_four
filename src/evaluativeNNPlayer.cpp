// C++ file defining the EvaluativeNNPlayer class

#include "evaluativeNNPlayer.h"

EvaluativeNNPlayer::EvaluativeNNPlayer(NeuralNetwork* network) : nn(network)
{

}

int EvaluativeNNPlayer::move(const Board& board)
{
	// Generate and evaluate boards for each of the possible moves and save index of largest evaluation
	Board boards[7] = {board, board, board, board, board, board, board};
	float evaluations[7];
	float largest = -100;
	int index = 0;
/*	for(int i = 0; i < 7; i++)
	{
		if(!boards[i].placePiece(i, isWhite)) // Succeeded
		{
			nn->forwardProp(boards[i], evaluations[i]);
		}
		else
			evaluations[i] = -100;
		if(evaluations[i] > largest)
		{
			largest = evaluations[i];
			index = i;
		}
	}
*/
	return rand() % 7;
}
