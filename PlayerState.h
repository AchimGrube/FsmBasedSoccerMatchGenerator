#pragma once

#include "_functions.h"

class Player;
class Pitch;
class Ball;
class Match;

class PlayerState abstract
{
public:

	void beginTurn(Player&, Pitch&);
	void endTurn(Player&, Pitch&);

	virtual void doAction(Player&, Match&) = 0;
};