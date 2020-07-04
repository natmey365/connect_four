// C++ header file defining the EvaluativeNNPlayer class

#ifndef EvaluativeNNPLAYER_H
#define EvaluativeNNPLAYER_H

#include "player.h"
#include "neural_network.h"
#include "layer.h"
#include "perceptron.h"
#include "activations.h"
#include "board.h"

class EvaluativeNNPlayer : public Player
{
	public:
		EvaluativeNNPlayer(Neural_Network network);
		int move(Board *board);

	private:
		Neural_Network nn;
		float evaluations[7];
		Board moves[7];
};

#endif
