// C++ file defining functions for converting Connect Four boards to Neural Network inputs

void one_hot(board b, float *nn_inputs)
{
	int space_status;
	for(int i = 0; i < 6; i++)
	{
		for(int j = 0; j < 7; j++)
		{
			if(b.spaceStatus(i, j) == 0)
			{
				nn_inputs[i*j*3]   = 1;
				nn_inputs[i*j*3+1] = 0;
				nn_inputs[i*j*3+2] = 0;
			}
			else if(b.spaceStatus(i, j) == 1)
			{
				nn_inputs[i*j*3]   = 0;
				nn_inputs[i*j*3+1] = 1;
				nn_inputs[i*j*3+2] = 0;
			}
			else
			{
				nn_inputs[i*j*3]   = 0;
				nn_inputs[i*j*3+1] = 0;
				nn_inputs[i*j*3+2] = 1;
			}
		}
	}
}
