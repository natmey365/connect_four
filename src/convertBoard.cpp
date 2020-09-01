// C++ file defining functions for converting Connect Four boards to Neural Network inputs

#include "convertBoard.h"

void flatten_one_hot(const Board& b, float *nn_inputs)
{
	int x = 0;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if(b.spaceStatus(i, j) == 0)
			{
				nn_inputs[x++] = 1;
				nn_inputs[x++] = 0;
				nn_inputs[x++] = 0;
			}
			else if(b.spaceStatus(i, j) == 1)
			{
				nn_inputs[x++] = 0;
				nn_inputs[x++] = 1;
				nn_inputs[x++] = 0;
			}
			else
			{
				nn_inputs[x++] = 0;
				nn_inputs[x++] = 0;
				nn_inputs[x++] = 1;
			}
		}
	}
}

void flatten_trinary(const Board& b, float *nn_inputs)
{       
        int x = 0;
        for(int i = 0; i < 6; i++)
        {       
                for(int j = 0; j < 7; j++)
                {       
                        nn_inputs[x++] = b.spaceStatus(i, j);
		}
        }
}
