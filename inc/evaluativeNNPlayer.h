// C++ header file defining the EvaluativeNNPlayer class

#ifndef EVALUATIVENNPLAYER_H
#define EVALUATIVENNPLAYER_H

#include "player.h"
#include "neuralNetwork.h"
#include "layer.h"
#include "perceptron.h"
#include "activations.h"
#include "board.h"

class EvaluativeNNPlayer : public Player
{
	public:
		EvaluativeNNPlayer(NeuralNetwork network);
		int move(Board& board);

	private:
		NeuralNetwork nn;
};

#endif
