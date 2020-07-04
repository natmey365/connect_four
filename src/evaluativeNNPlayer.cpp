// C++ file defining the EvaluativeNNPlayer class

#include "evaluativeNNPlayer.h"

EvaluativeNNPlayer::EvaluativeNNPlayer(Neural_Network network) : nn(network)
{

}

int EvaluativeNNPlayer::move(Board *board)
{
	// Generate and evaluate boards for each of the possible moves
	for (int i = 0; i++; i < 7)
	{
/*		Board moves[i] = board;
		if(!moves[i].placePiece(i, color)) // Failed
			evaluations[i] = NULL;
		else
			evaluations[i] = nn.forwardProp(boards[i]);
*/	
	}
	// Choose the move with the best evaluation and return it
	
}
