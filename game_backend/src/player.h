// Header file defining the Player class

#ifndef PLAYER_H
#define PLAYER_H

class Player
{
	public:
		virtual int move(Board *board) = 0;
};

class RandomPlayer : public Player
{
	public:
		RandomPlayer();
		int move(Board *board);
};

#endif
