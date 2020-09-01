// C++ header file defining functions for converting Connect Four boards to Neural Network inputs
#ifndef CONVERTBOARD_H
#define CONVERTBOARD_H

#include "board.h"

void flatten_one_hot(Board b, float *nn_inputs);
void flatten_trinary(Board b, float *nn_inputs);

#endif
