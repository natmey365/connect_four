// C++ file defining the EvaluativeNNPlayer class

#include "evaluativeNNPlayer.h"

EvaluativeNNPlayer::EvaluativeNNPlayer(NeuralNetwork network) : nn(network)
{

}

int EvaluativeNNPlayer::move(Board& board)
{
	// Generate and evaluate boards for each of the possible moves
	Board boards[7];
	for(int i = 0; i < 6; i++)
	{
		boards[i] = board;
		//if(!boards[i].placePiece(i, isWhite)) // Failed
		//	evaluations[i] = NULL;
		//else
		//	evaluations[i] = 1;//nn.forwardProp(boards[i]);	
	}
	// Choose the move with the best evaluation and return it
}
