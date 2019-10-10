#pragma once

#include "_functions.h"

class Player;
class Pitch;
class Ball;

class PlayerState abstract
{
public:

	void beginTurn(Player&, Pitch&);
	void endTurn(Player&, Pitch&);

	virtual void doAction(Player&, Pitch&, Ball&) = 0;
};