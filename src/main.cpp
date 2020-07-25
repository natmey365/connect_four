// Top level C++ file

#include "main.h"

int main(int argc, char* argv[])
{
	bool verbose = false;
	for(int i = 1; i < argc; i++)
	{
		if(!strcmp(argv[i], "-v"))
			verbose = true;
	}
	Game game(new RandomPlayer, new RandomPlayer, verbose);
	std::cout << game.play() << std::endl;
}
