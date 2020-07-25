// C++ file defining the Player class

#include "player.h"

void Player::setColor(bool b)
{
	isWhite = b;
}

bool Player::getColor()
{
	return isWhite;
}
