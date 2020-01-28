// C++ file defining the Space class

#include <iostream>
#include <string>
#include "space.h"

Space::Space() : status("blank")
{
	std::cout << "Space Constructor\n";
}

bool Space::isBlank()
{
	if (status.compare("blank") == 0)
		return true;
	return false;
}
