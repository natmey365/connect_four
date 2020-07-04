// C++ file defining the EvaluativeNNPlayer class

#include "evaluativeNNPlayer.h"

EvaluativeNNPlayer::EvaluativeNNPlayer(Neural_Network network) : nn(network)
{

}

int EvaluativeNNPlayer::move(Board *board)
{
	// Generate boards for each of the possible moves
	Board boards[7] = board->placePiece;

	// Evaluate the positions, save evaluations in evaluations
}
