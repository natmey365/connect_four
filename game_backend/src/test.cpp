#include <iostream>

int randomNum()
{
	int i = rand() % 6;
	std::cout << i << std::endl;
	return i;
}

int main()
{
	srand(time(NULL));

	while(randomNum()){}
}
