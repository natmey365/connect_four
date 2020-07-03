// C++ header file defining the NNPlayer class

#ifndef NNPLAYER_H
#define NNPLAYER_H

#include "neural_network.h"
#include "layer.h"
#include "perceptron.h"
#include "activations.h"
#include "board.h"

class NNPlayer : public Player
{
	public:
		NNPlayer(Neural_Network network);
		int move(Board board);

	Private:
		Neural_Network nn;
		float evaluatins[7];
		board moves[7]
};

#endif
