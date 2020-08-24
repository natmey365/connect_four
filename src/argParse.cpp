// C++ file defining the Game class

#include "argParse.h"

void argParse(int argc, char* argv[], bool& verbose)
{
	verbose = false;
	for(int i = 1; i < argc; i++)
	{
		if(!strcmp(argv[i], "-v"))
			verbose = true;
	}
}
